setenv('MW_MINGW64_LOC', [pwd, '\mingw64_mini_cv\']);
mex -setup;
%mex -setup c++;
loadlibrary([pwd, '\USB5000.dll'], [pwd, '\USB5000.h']);
%libfunctions USB5000 -full

calllib('USB5000','USB5OpenDevice',0)

for i=1:8
    calllib('USB5000','SetUSB5AiChanSel',0,i - 1 ,0)
    calllib('USB5000','SetUSB5AiRange',0,i - 1 ,10)
end

for i = 1:3
    calllib('USB5000','SetUSB5AiChanSel',0, i - 1, 1)
    calllib('USB5000','SetUSB5AiRange',0, i - 1, 5)
end 

calllib('USB5000', 'SetUSB5AiOneShotPoints', 0, 500)
calllib('USB5000', 'SetUSB5AiSampleMode', 0, 1)      
calllib('USB5000', 'SetUSB5AiSampleRate', 0, 2000)
calllib('USB5000', 'SetUSB5AiConvSource', 0, 0)
calllib('USB5000', 'SetUSB5AiPreTrigPoints', 0, 0)
calllib('USB5000', 'SetUSB5ClrAiFifo',0)
calllib('USB5000', 'SetUSB5AiTrigSource', 0, 1)

Data = zeros(1, 10000);
DataPtr = libpointer('singlePtr', Data);

while(1)
    fifo_ = calllib('USB5000', 'USB5GetAi', 0, 500, DataPtr, 100)
    Data = get(DataPtr,'Value');
    calllib('USB5000', 'SetUSB5ClrAiFifo', 0)
    calllib('USB5000', 'SetUSB5ClrAiTrigger', 0)
    
    ch1 = zeros(1, 500);
    ch2 = zeros(1, 500);
    ch3 = zeros(1, 500);
    
    ch1 = Data(1:500);     %Q                                  
    ch2 = Data(501:1000);  %I                                       
    ch3 = Data(1001:1500); %dac

    fifo_
end

calllib('USB5000', 'SetUSB5ClrAiTrigger', 0)
calllib('USB5000', 'SetUSB5ClrAiFifo', 0)
calllib('USB5000', 'USB5CloseDevice', 0)
clear all;
unloadlibrary('USB5000')

