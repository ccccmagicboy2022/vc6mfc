import os
import numpy as np
import pandas as pd
from PyQt5 import QtCore
import multiprocessing
import time


def fft(data, fft_size=1024, sample_rate=1024, deg=False):
    '''
    get d frequency-domain info
    :param data: 1D numpy array
    :param fft_size:  integration period, must be multi-periods
    :return: frequency-domain spectrogram
    '''
    xs = data[: fft_size]

    win = np.hanning(fft_size)
    win /= np.sum(win)
    xs = xs * win

    xf = np.fft.fft(xs) #/ (fft_size / 2)
    # xf[0] = xf[0]/2
    freqs = np.arange(0, fft_size // 2, dtype='float') * sample_rate / fft_size
    # xfp = 20 * np.log10(np.clip(np.abs(xf), 1E-20, 1E100))
    xfp = np.abs(xf) * np.sqrt(2)

    N_OFFSET = fft_size // 2
    return freqs[:N_OFFSET], xfp[:N_OFFSET], np.angle(xf[:N_OFFSET], deg=deg)

def apfft(dat, fft_size=128, sample_rate=1024, window=2, log=False, deg=False):

    x = dat[:2*fft_size-1]
    if window == 0:
        win = np.ones(fft_size)
        win = np.convolve(win, win)
        win = win / np.sum(win)
    elif window == 1:
        win = np.ones(fft_size)
        win1 = np.hanning(fft_size)
        win = np.convolve(win, win1)
        win = win / np.sum(win)
    elif window == 2:
        win = np.hanning(fft_size)
        win = np.convolve(win, win)
        win = win / np.sum(win)

    x = x * win
    x = x[fft_size-1:] + np.hstack(([0], x[:fft_size-1]))
    
    xf = np.fft.fft(x)
    # xf[0] = xf[0]/2

    xf = xf[:fft_size//2]

    freqs = np.arange(0, fft_size // 2, dtype='float') * sample_rate / fft_size

    xfp = np.abs(xf) if log is False else 20*np.log10(np.abs(xf))
    xfp = xfp * np.sqrt(2) 

    return freqs, xfp, np.angle(xf, deg=deg)

def harmonic_analysis(xf1, phase1, xf2, phase2, fft_size=128, sample_rate=934534):
    max2 = np.argmax(xf2)
    w = (phase1[max2] - phase2[max2])
    if w > np.pi:
        w -= 2*np.pi
    elif w < -np.pi:
        w += 2*np.pi
    delta_k = w * fft_size / (fft_size - 1) / np.pi
    base_k = max2+delta_k if max2+delta_k > 0.5 else 1
    base_wfreq = base_k * sample_rate / fft_size
    return base_k, base_wfreq 

# ph0 = 0
def harmonic_table(ph0, channel_name, xf1, phase1, xf2, phase2, base_index, base_freq, harmonic_limit=64):
    # global ph0
    harmonic_counts = int(len(xf1) / base_index)
    harmonic_counts = harmonic_limit if harmonic_counts>harmonic_limit else harmonic_counts
    d = {
        'Freq': [base_freq*i for i in range(harmonic_counts)],
        'RMS': [xf1[int(round(i*base_index))]**2/xf2[int(round(i*base_index))] \
            if xf2[int(round(i*base_index))]/xf2[int(round(1*base_index))]>0.0005 and \
                abs(xf2[int(round(1*base_index))])>1E-20 else 0 for i in range(harmonic_counts)],
        'Phase': [phase2[int(round(i*base_index))]/np.pi*180 \
            if xf2[int(round(i*base_index))]/xf2[int(round(1*base_index))]>0.0005 and \
                abs(xf2[int(round(1*base_index))])>1E-20 else 0 for i in range(harmonic_counts)]
    }
    d['Phase'][0], d['RMS'][0] = 0, xf2[0]
    ph0 = d['Phase'][1]*1 if channel_name in ['UA', 'U1'] else ph0
    for i in range(1,harmonic_counts):
        if d['RMS'][i] > 1E-20:
            d['Phase'][i] -= ph0*i
            if d['Phase'][i]>=360:
                d['Phase'][i] -= int((d['Phase'][i])/360) * 360
            elif d['Phase'][i]<0:
                d['Phase'][i] += int((360-d['Phase'][i])/360) * 360
    return {key: np.array(dat) for key, dat in d.items()}, ph0
    
def worker(parameters, return_dict):
    fft_max_size = 8192
    dat = parameters['data']
    harmonic_num = parameters['harmonic_num']
    sample_rate = parameters['sample_rate']
    downsample = parameters['downsample']
    ph0 = parameters['ph0']
    sample_rate /= downsample

    fft_size = 2**int(np.log2(len(dat)/2))
    if fft_size > fft_max_size*2:
        n = fft_size // fft_max_size
        dat = dat[::n]
        sample_rate /= n
        fft_size = fft_max_size
    elif fft_size > fft_max_size:
        fft_size = fft_max_size
    # fft_size = fft_size if fft_size<fft_max_size else fft_max_size
    # fft_size = parameters['fft_size']
    freq1, xf1, phase1 = fft(dat[fft_size-1:fft_size-1+fft_size], fft_size=fft_size, sample_rate=sample_rate, deg=False)
    freq2, xf2, phase2 = apfft(dat[:fft_size+fft_size], fft_size=fft_size, sample_rate=sample_rate, window=2, deg=False)

    base_index, base_wfreq = harmonic_analysis(xf1, phase1, xf2, phase2, fft_size=fft_size, sample_rate=sample_rate)
    df_array, ph0 = harmonic_table(ph0, parameters['channel'], xf1, phase1, xf2, phase2, base_index, base_wfreq, harmonic_limit=harmonic_num)

    return_dict['channel'] = parameters['channel']
    return_dict['freq1'] = freq1
    return_dict['xf1'] = 20 * np.log10(np.clip(np.abs(xf1), 1E-20, 1E100)) #xf1
    
    return_dict['phase1'] = phase1
    return_dict['freq2'] = freq2
    return_dict['xf2'] = 20 * np.log10(np.clip(np.abs(xf2), 1E-20, 1E100))  #xf2
    return_dict['phase2'] = phase2
    return_dict['df_array'] = df_array

    return_dict['ph0'] = ph0

    return return_dict
    

class SpectromAnalyzer(QtCore.QObject):
    spectrum_updated = QtCore.pyqtSignal(object)
    harmonic_updated = QtCore.pyqtSignal(object)

    def __init__(self, comboBoxHarmonicChannel, parent=None, logger=None):
        super().__init__(parent)
        self.sample_rate = 934598
        self.comboBoxHarmonicChannel = comboBoxHarmonicChannel
        self.logger = logger
        # pd.set_option('float_format', lambda x: f'{x:,.0e}')

        self.numprocess, self.index = 8, 0
        self.pool = multiprocessing.Pool(self.numprocess)
        
        manager = multiprocessing.Manager()
        self.parameters = [manager.dict() for _ in range(self.numprocess)]
        self.return_dict = [manager.dict() for _ in range(self.numprocess)]

        self.ph0 = 0
        self.last_refresh = {}
        self.counts = {}
        self.intergral_time = 1
        self.pre_update_time = {}
        self.tmp_data_array, self.latest_harmonic_table = {}, {}
        self.skip_counts = 0
    
    def setup(self, harmonic_num):
        self.harmonic_num = harmonic_num
        self.pre_update_time, self.counts, self.tmp_data_array, self.latest_harmonic_table = {}, {}, {}, {}
        self.skip_counts = 0
    
    def set_sample_rate(self, sample_rate=25600):
        self.sample_rate = sample_rate
        
    def feed(self, dat):
        name = dat['channel']
        if name not in self.last_refresh.keys():
            self.last_refresh[name] = 0
        now = time.time()
        ch_num = len(self.pre_update_time.keys())
        if now - self.last_refresh[name] <= 0.02 or (ch_num > 0  and self.skip_counts % ch_num != 0):
            self.skip_counts += 1
            return
        self.skip_counts = 0
        self.last_refresh[name] = now
        self.index = self.index + 1 if self.index < (self.numprocess - 1) else 0

        self.parameters[self.index]['channel'] = dat['channel']
        self.parameters[self.index]['downsample'] = dat['downsample']
        self.parameters[self.index]['data'] = dat['data']
        self.parameters[self.index]['sample_rate'] = self.sample_rate
        self.parameters[self.index]['harmonic_num'] =self.harmonic_num
        self.parameters[self.index]['ph0'] =self.ph0

        self.pool.apply_async(worker, 
                              args=(self.parameters[self.index], self.return_dict[self.index]),
                              callback=self.pasrse_output)
    
    def table(self, channel_name, data_array):
        try:
            if channel_name not in self.counts.keys():
                self.counts[channel_name] = 0
                self.latest_harmonic_table[channel_name] = None
                self.pre_update_time[channel_name] = 0
            now = time.time()
            self.tmp_data_array[channel_name] = {key: data_array[key] if key not in ['Phase'] else np.cos(data_array[key]/180*np.pi) \
                for key in data_array.keys()} if self.counts[channel_name] == 0 else \
                    {key: data_array[key]+self.tmp_data_array[channel_name][key] if key not in ['Phase'] else np.cos(data_array[key]/180*np.pi) \
                        + self.tmp_data_array[channel_name][key] for key in data_array.keys()}
            self.counts[channel_name] += 1

            if now - self.pre_update_time[channel_name] >= self.intergral_time:
                self.latest_harmonic_table[channel_name] = pd.DataFrame({key: self.tmp_data_array[channel_name][key]/self.counts[channel_name] \
                    if key not in ['Phase'] else abs(np.arccos(self.tmp_data_array[channel_name][key]/self.counts[channel_name])/np.pi*180 \
                        - 360 * (data_array['Phase'] // 180)) for key in self.tmp_data_array[channel_name].keys()})
                self.pre_update_time[channel_name], self.counts[channel_name] = now, 0
                
            self.latest_harmonic_table[channel_name] = pd.DataFrame(self.tmp_data_array[channel_name]) if self.latest_harmonic_table[channel_name] is None else \
                self.latest_harmonic_table[channel_name]
        except Exception as e:
            del self.tmp_data_array[channel_name]
            self.logger.exception(e)

        return self.latest_harmonic_table
        # return self.latest_harmonic_table[channel_name]
        
    def pasrse_output(self, res):
        self.spectrum_updated.emit(res)
        # if self.comboBoxHarmonicChannel.currentText() == res['channel']:
        #     df_table = self.table(res['channel'], res['df_array'])
        #     self.harmonic_updated.emit(df_table.round(0))
        self.ph0 = res['ph0']
        df_table_json = self.table(res['channel'], res['df_array'])
        self.harmonic_updated.emit(df_table_json)


if __name__ == '__main__':
    import struct
    import matplotlib.pyplot as plt 

    filename = 'waveIA20190912_152314.dat'
    sa = SpectromAnalyzer()

    sample_rate = 2048
    fft_size = 2048
    freq = 5.5
    A = 5000 * np.sqrt(2)

    t = np.arange(-fft_size+1, 2*fft_size) / sample_rate

    # with open(filename, mode='rb') as f:
    #     buf = f.read(2*fft_size*4)
    #     y = struct.unpack_from("<{size}f".format(size=2*fft_size), buffer=buf)
    x = A*np.cos(2*np.pi*freq*t+0/180*np.pi) + \
        0.5*A*np.cos(2*2*np.pi*freq*t+30/180*np.pi) + \
        0.4*A*np.cos(3*2*np.pi*freq*t+60/180*np.pi) + \
        0.3*A*np.cos(4*2*np.pi*freq*t+90/180*np.pi) + \
        0.2*A*np.cos(5*2*np.pi*freq*t+120/180*np.pi)
    x = x.astype(np.int32)
    

    freq1, xfp1, phase1, freq2, xfp2, phase2, df = sa.feed(x, fft_size=fft_size, sample_rate=sample_rate)
    print(df)

    fig = plt.figure()
    ax1 = fig.add_subplot(2,1,1)
    # ax1.plot(freq1, xfp1, color='r', label='fft')
    ax1.plot(freq2, xfp2, color='g', label='apfft')
    # ax1.plot(freq21, xfp21, color='r', label='raw-apfft')
    ax1.legend()
    ax1.grid()

    ax1 = fig.add_subplot(2,1,2)
    ax1.plot(x, color='g', label='signal')
    # ax1.plot(y, color='r', label='raw')
    # ax1.plot(freq1, phase1, color='g', label='fft')
    # ax1.plot(freq2, phase2, color='r', label='apfft')
    ax1.legend()
    ax1.grid()

    plt.show()
    