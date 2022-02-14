import sys, logging

from UVSOCK import uvsock
from UVSOCK.interface import UVInterface


class UVClient(object):

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

        self.phy = UVInterface(host=host, port=port, logger=logger)
    
    def open(self):
        self.phy.open()

    def close(self):
        self.phy.close()

    def get_version(self):
        uv = uvsock.UVSOCK_CMD(uvsock.UV_GEN_GET_VERSION)
        cmd_byte = uv.pack()
        r = self.phy.send(cmd_byte)
        status, version = uv.retrive_version(r)
        return status, version

    def calc_expression(self, expr):
        ve = uvsock.VSET()
        uv = uvsock.UVSOCK_CMD(uvsock.UV_DBG_CALC_EXPRESSION, data=ve.pack(uvsock.VTT_void, 0, expr))
        cmd_byte = uv.pack()
        r = self.phy.send(cmd_byte)
        status, val_type, val, sstr = uv.retrive_expression(r)
        return status, val_type, val, sstr

    def read_chunk_mem(self, addr, nBytes):
        vm = uvsock.AMEM()
        uv = uvsock.UVSOCK_CMD(uvsock.UV_DBG_MEM_READ, data=vm.pack(addr, nBytes))
        cmd_byte = uv.pack()
        r = self.phy.send(cmd_byte)
        status, nAddr, ErrAddr, nErr, r_data = uv.retrive_mem_data(r)
        return status, nAddr, ErrAddr, nErr, r_data

if __name__ == "__main__":
    client = UVClient()

    # version = client.get_version()
    # print(version)

    r = client.calc_expression('SData_UA')
    print(r)

    print(hex(r[2]))

    r = client.read_chunk_mem(r[2], 12)
    print(r)

    print(r[-1].hex())

    