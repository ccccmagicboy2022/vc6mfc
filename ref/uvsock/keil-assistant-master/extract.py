'''
wave文件数据解析示例
'''
import os
import struct


def getsize(filename):
    '''
    return: 文件中所包含的数据点长度，每个数据点占 4 Bytes
    '''
    return os.path.getsize(filename) // 4

def decode(filename, offset=0, size=2048):
    '''
    解析wave文件中数据
    offset: 解析起始位置
    size:   解析数据长度
    waring: offset + size < getsize(filename)

    return: 长度为size的数据tuple
    '''
    if offset + size >= getsize(filename):
        return None

    with open(filename, mode='rb') as f:
        f.seek(offset*4)
        buf = f.read(size*4)
        return struct.unpack_from("<{size}f".format(size=size), buffer=buf)
    
    return None


if __name__ == "__main__":
    import matplotlib.pyplot as plt

    data = decode("wave4_20190921_092629.dat", offset=0, size=4096)

    plt.plot(data)
    plt.grid()
    plt.show()