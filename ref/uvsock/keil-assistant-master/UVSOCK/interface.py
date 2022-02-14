"""
UVSOCK. TCP/IP
"""
import sys
import logging
import socket
import time

import UVSOCK.uvsock


class UVInterface(object):
    '''
    Physical Interface, support serial and tcp now.
    '''
    _max_number = 10240      # 每包最大字节数
    _timeout_unit = 0.01    # seconds socket.recv 超时
    _timeout_counts = 500   # 允许超时次数

    def __init__(self, host="127.0.0.1", port=4823, logger=None):
        if logger is None:
            self.logger = logging.getLogger(__name__)
            self.logger.setLevel(logging.INFO)
            handler = logging.StreamHandler(sys.stdout)
            formatter = logging.Formatter('%(asctime)s - %(name)s - %(levelname)s - %(message)s')
            handler.setFormatter(formatter)
            self.logger.addHandler(handler)
        else:
            self.logger = logger
        self.host, self.port = host, port
        self.client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        # self.open()
    
    def __del__(self):
        self.client.close()

    def open(self):
        self.client.connect((self.host, self.port))
        self.client.settimeout(self._timeout_unit)

    def close(self):
        self.client.close()

    def send(self, data, ack=None, limit=40):
        '''
        发送命令， data是已经打包好的命令数据
        return:  命令对应的返回数据或 None
        '''
        self.clear_buf()
        self.client.send(data)
        
        return self.recv(ack=ack, limit=limit)

    def recv(self, ack=None, limit=40):
        '''
        命令 原始数据接收
        '''
        timeout_counts = 0
        while timeout_counts < self._timeout_counts:
            try:
                self.recv_buf += self.client.recv(self._max_number)
            except:
                timeout_counts += 1
                time.sleep(self._timeout_unit)
            finally:
                if ack is None and len(self.recv_buf)>=limit:
                    return self.recv_buf

                if ack is not None and ack in self.recv_buf:
                    return self.recv_buf

                if timeout_counts > self._timeout_counts:
                    self.logger.error('Do not recieve response')
                    return None

        self.logger.error('Do not recieve response')
        return None

    def clear_buf(self):
        self.recv_buf = b''


if __name__ == "__main__":
    phy = UVInterface()

    formatter = uvsock.UVSOCK_CMD(m_eCmd=1, data=b'')  
    d = formatter.pack()

    r = phy.send(d)
    print(d)
    print(r)