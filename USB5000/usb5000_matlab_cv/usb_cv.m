setenv('MW_MINGW64_LOC', [pwd, '\mingw64_mini_cv\']);
mex -setup;
%mex -setup c++;
loadlibrary([pwd, '\USB5000.dll'], [pwd, '\USB5000.h']);
%libfunctions USB5000 -full

calllib('USB5000','USB5OpenDevice',0)

for i=1:5
    calllib('USB5000','SetUSB5AiChanSel',0,i - 1 ,0)
    calllib('USB5000','SetUSB5AiRange',0,i - 1 ,5)
end
for i = 1:5
    calllib('USB5000','SetUSB5AiChanSel',0, i - 1, 1)   % 启用通道1-5
    calllib('USB5000','SetUSB5AiRange',0, i - 1, 5)     % -5V~5V
end 

calllib('USB5000','SetUSB5AiSampleMode',0,0)                %0为连续采集模式      
calllib('USB5000','SetUSB5AiSampleRate',0,200000)             %2000ns=2us=500k samples/s
calllib('USB5000','SetUSB5AiTrigSource',0,0)                %0软件触发采集
calllib('USB5000','SetUSB5AiConvSource',0,0)                %内部采集时针，也就是上面的500k
calllib('USB5000','SetUSB5AiPreTrigPoints',0,0)             %无需预触发 设置0即可
calllib('USB5000','SetUSB5ClrAiFifo',0)                     %清空采集卡Fifo缓冲区
calllib('USB5000','SetUSB5AiSoftTrig',0)

Data = zeros(1,1000*10);                                      %初始化一个空矩阵  长度要大于等于获取的点数乘开启通道数 
DataPtr = libpointer('singlePtr',Data);

while(1)
    fifo_ = calllib('USB5000','USB5GetAi',0, 1000, DataPtr, 4000)       %取1000组数据
    Data = get(DataPtr,'Value');
    ch1 = zeros(1,1000);                                             
    ch1 = Data(1:1000); 
    ch2 = zeros(1,1000);                                             
    ch2 = Data(1001:2000); 
    ch3 = zeros(1,1000);                                             
    ch3 = Data(2001:3000); 
    ch4 = zeros(1,1000);                                             
    ch4 = Data(3001:4000); 
    ch5 = zeros(1,1000);                                             
    ch5 = Data(4001:5000); 

    fifo_
end


calllib('USB5000','SetUSB5ClrAiTrigger',0)                  %清除Ai触发源       
calllib('USB5000','SetUSB5ClrAiFifo',0)                     %清空Fifo缓冲区
calllib('USB5000','USB5CloseDevice',0)                      %关闭采集卡  
clear all;
unloadlibrary('USB5000')

