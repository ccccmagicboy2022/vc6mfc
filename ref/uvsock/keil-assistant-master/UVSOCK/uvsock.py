import struct

# UV_OPERATION
UV_NULL_CMD = 0x0000 
UV_GEN_GET_VERSION = 0x0001 
UV_GEN_UI_UNLOCK = 0x0002 
UV_GEN_UI_LOCK = 0x0003 
UV_GEN_HIDE = 0x0004
UV_GEN_SHOW = 0x0005 
UV_GEN_RESTORE = 0x0006 
UV_GEN_MINIMIZE = 0x0007 
UV_GEN_MAXIMIZE = 0x0008 
UV_GEN_EXIT = 0x0009 
UV_GEN_GET_EXTVERSION = 0x000A 
UV_GEN_CHECK_LICENSE = 0x000B 
UV_GEN_CPLX_COMPLETE = 0x000C 
UV_GEN_SET_OPTIONS = 0x000D 
UV_PRJ_LOAD = 0x1000 
UV_PRJ_CLOSE = 0x1001 
UV_PRJ_ADD_GROUP = 0x1002 
UV_PRJ_DEL_GROUP = 0x1003 
UV_PRJ_ADD_FILE = 0x1004 
UV_PRJ_DEL_FILE = 0x1005 
UV_PRJ_BUILD = 0x1006 
UV_PRJ_REBUILD = 0x1007 
UV_PRJ_CLEAN = 0x1008 
UV_PRJ_BUILD_CANCEL = 0x1009 
UV_PRJ_FLASH_DOWNLOAD = 0x100A 
UV_PRJ_GET_DEBUG_TARGET = 0x100B 
UV_PRJ_SET_DEBUG_TARGET = 0x100C 
UV_PRJ_GET_OPTITEM = 0x100D 
UV_PRJ_SET_OPTITEM = 0x100E 
UV_PRJ_ENUM_GROUPS = 0x100F 
UV_PRJ_ENUM_FILES = 0x1010 
UV_PRJ_CMD_PROGRESS = 0x1011 
UV_PRJ_ACTIVE_FILES = 0x1012 
UV_PRJ_FLASH_ERASE = 0x1013 
UV_PRJ_GET_OUTPUTNAME = 0x1014 
UV_PRJ_ENUM_TARGETS = 0x1015 
UV_PRJ_SET_TARGET = 0x1016 
UV_PRJ_GET_CUR_TARGET = 0x1017 
UV_PRJ_SET_OUTPUTNAME = 0x1018 
UV_DBG_ENTER = 0x2000 
UV_DBG_EXIT = 0x2001 
UV_DBG_START_EXECUTION = 0x2002 
UV_DBG_RUN_TO_ADDRESS = 0x2102 
UV_DBG_STOP_EXECUTION = 0x2003 
UV_DBG_STATUS = 0x2004 
UV_DBG_RESET = 0x2005 
UV_DBG_STEP_HLL = 0x2006 
UV_DBG_STEP_HLL_N = 0x2106 
UV_DBG_STEP_INTO = 0x2007 
UV_DBG_STEP_INTO_N = 0x2107 
UV_DBG_STEP_INSTRUCTION = 0x2008 
UV_DBG_STEP_INSTRUCTION_N = 0x2108 
UV_DBG_STEP_OUT = 0x2009 
UV_DBG_CALC_EXPRESSION = 0x200A 
UV_DBG_MEM_READ = 0x200B 
UV_DBG_MEM_WRITE = 0x200C 
UV_DBG_TIME_INFO = 0x200D 
UV_DBG_SET_CALLBACK = 0x200E 
UV_DBG_VTR_GET = 0x200F 
UV_DBG_VTR_SET = 0x2010 
UV_DBG_SERIAL_GET = 0x2011 
UV_DBG_SERIAL_PUT = 0x2012 
UV_DBG_VERIFY_CODE = 0x2013 
UV_DBG_CREATE_BP = 0x2014 
UV_DBG_ENUMERATE_BP = 0x2015 
UV_DBG_CHANGE_BP = 0x2016 
UV_DBG_ENUM_SYMTP = 0x2017 
UV_DBG_ADR_TOFILELINE = 0x2018 
UV_DBG_ENUM_STACK = 0x2019 
UV_DBG_ENUM_VTR = 0x201A 
UV_DBG_UNUSED = 0x201B 
UV_DBG_ADR_SHOWCODE = 0x201C 
UV_DBG_WAKE = 0x201D 
UV_DBG_SLEEP = 0x201E 
UV_MSGBOX_MSG = 0x201F 
UV_DBG_EXEC_CMD = 0x2020 
UV_DBG_POWERSCALE_SHOWCODE = 0x2021 
UV_DBG_POWERSCALE_SHOWPOWER = 0x2022 
POWERSCALE_OPEN = 0x2023 
UV_DBG_EVAL_EXPRESSION_TO_STR = 0x2024 
UV_DBG_FILELINE_TO_ADR = 0x2025 
UV_DBG_ENUM_REGISTER_GROUPS = 0x2026 
UV_DBG_ENUM_REGISTERS = 0x2027 
UV_DBG_READ_REGISTERS = 0x2028 
UV_DBG_REGISTER_SET = 0x2029 
UV_DBG_DSM_READ = 0x202A 
UV_DBG_EVAL_WATCH_EXPRESSION = 0x202B 
UV_DBG_REMOVE_WATCH_EXPRESSION = 0x202D 
UV_DBG_ENUM_VARIABLES = 0x202E 
UV_DBG_VARIABLE_SET = 0x202F 
UV_DBG_ENUM_TASKS = 0x2030 
UV_DBG_ENUM_MENUS = 0x2031 
UV_DBG_MENU_EXEC = 0x2032 
UV_DBG_ITM_REGISTER = 0x2033 
UV_DBG_ITM_UNREGISTER = 0x2034 
UV_DBG_EVTR_REGISTER = 0x2035 
UV_DBG_EVTR_UNREGISTER = 0x2036 
UV_DBG_EVTR_GETSTATUS = 0x2037 
UV_DBG_EVTR_ENUMSCVDFILES = 0x2038 
UV_CMD_RESPONSE = 0x3000 
UV_ASYNC_MSG = 0x4000 
UV_PRJ_BUILD_COMPLETE = 0x5000 
UV_PRJ_BUILD_OUTPUT = 0x5001 
UV_DBG_CALLBACK = 0x5002 
UV_DBG_BP_ENUM_START = 0x5004 
UV_DBG_BP_ENUMERATED = 0x5005 
UV_DBG_BP_ENUM_END = 0x5006 
UV_PRJ_ENUM_GROUPS_START = 0x5007 
UV_PRJ_ENUM_GROUPS_ENU = 0x5008 
UV_PRJ_ENUM_GROUPS_END = 0x5009 
UV_PRJ_ENUM_FILES_START = 0x500A 
UV_PRJ_ENUM_FILES_ENU = 0x500B 
UV_PRJ_ENUM_FILES_END = 0x500C 
UV_PRJ_PBAR_INIT = 0x500D 
UV_PRJ_PBAR_STOP = 0x500E 
UV_PRJ_PBAR_SET = 0x500F 
UV_PRJ_PBAR_TEXT = 0x5010 
UV_DBG_ENUM_SYMTP_START = 0x5011 
UV_DBG_ENUM_SYMTP_ENU = 0x5012 
UV_DBG_ENUM_SYMTP_END = 0x5013 
UV_DBG_ENUM_STACK_START = 0x5014 
UV_DBG_ENUM_STACK_ENU = 0x5015 
UV_DBG_ENUM_STACK_END = 0x5016 
UV_DBG_ENUM_VTR_START = 0x5017 
UV_DBG_ENUM_VTR_ENU = 0x5018 
UV_DBG_ENUM_VTR_END = 0x5019 
UV_DBG_CMD_OUTPUT = 0x5020 
UV_DBG_SERIAL_OUTPUT = 0x5120 
UV_PRJ_ENUM_TARGETS_START = 0x5021 
UV_PRJ_ENUM_TARGETS_ENU = 0x5022 
UV_PRJ_ENUM_TARGETS_END = 0x5023 
UV_DBG_ENUM_REGISTER_GROUPS_START = 0x5024 
UV_DBG_ENUM_REGISTER_GROUPS_ENU = 0x5025 
UV_DBG_ENUM_REGISTER_GROUPS_END = 0x5026 
UV_DBG_ENUM_REGISTERS_START = 0x5027 
UV_DBG_ENUM_REGISTERS_ENU = 0x5028 
UV_DBG_ENUM_REGISTERS_END = 0x5029 
UV_DBG_ITM_OUTPUT = 0x5030 
UV_DBG_ENUM_VARIABLES_START = 0x5040 
UV_DBG_ENUM_VARIABLES_ENU = 0x5041 
UV_DBG_ENUM_VARIABLES_END = 0x5042 
UV_DBG_ENUM_TASKS_START = 0x5050 
UV_DBG_ENUM_TASKS_ENU = 0x5051 
UV_DBG_ENUM_TASKS_END = 0x5052 
UV_DBG_ENUM_MENUS_START = 0x5060 
UV_DBG_ENUM_MENUS_ENU = 0x5061 
UV_DBG_ENUM_MENUS_END = 0x5062 
UV_DBG_EVTR_OUTPUT = 0x5063 
UV_DBG_EVTR_ENUMSCVDFILES_START = 0x5064 
UV_DBG_EVTR_ENUMSCVDFILES_ENU = 0x5065 
UV_DBG_EVTR_ENUMSCVDFILES_END = 0x5066 
UV_RTA_MESSAGE = 0x6000 
UV_RTA_INCOMPATIBLE = 0x6001 
UV_TST_1 = 0xFF00 
UV_TST_2 = 0xFF01 
UV_TST_3 = 0xFF02 
UV_TST_4 = 0xFF03 
UV_TST_5 = 0xFF04 
UV_TST_6 = 0xFF05 
UV_TST_7 = 0xFF06 
UV_TST_8 = 0xFF07 
UV_TST_9 = 0xFF08 
UV_TST_10 = 0xFF09 

# UV_STATUS
UV_STATUS_SUCCESS = 0 
UV_STATUS_FAILED = 1 
UV_STATUS_NO_PROJECT = 2 
UV_STATUS_WRITE_PROTECTED = 3 
UV_STATUS_NO_TARGET = 4 
UV_STATUS_NO_TOOLSET = 5 
UV_STATUS_NOT_DEBUGGING = 6 
UV_STATUS_ALREADY_PRESENT = 7 
UV_STATUS_INVALID_NAME = 8 
UV_STATUS_NOT_FOUND = 9 
UV_STATUS_DEBUGGING = 10 
UV_STATUS_TARGET_EXECUTING = 11 
UV_STATUS_TARGET_STOPPED = 12 
UV_STATUS_PARSE_ERROR = 13 
UV_STATUS_OUT_OF_RANGE = 14 
UV_STATUS_BP_CANCELLED = 15 
UV_STATUS_BP_BADADDRESS = 16 
UV_STATUS_BP_NOTSUPPORTED = 17 
UV_STATUS_BP_FAILED = 18 
UV_STATUS_BP_REDEFINED = 19 
UV_STATUS_BP_DISABLED = 20 
UV_STATUS_BP_ENABLED = 21 
UV_STATUS_BP_CREATED = 22 
UV_STATUS_BP_DELETED = 23 
UV_STATUS_BP_NOTFOUND = 24 
UV_STATUS_BUILD_OK_WARNINGS = 25 
UV_STATUS_BUILD_FAILED = 26 
UV_STATUS_BUILD_CANCELLED = 27 
UV_STATUS_NOT_SUPPORTED = 28 
UV_STATUS_TIMEOUT = 29 
UV_STATUS_UNEXPECTED_MSG = 30 
UV_STATUS_VERIFY_FAILED = 31 
UV_STATUS_NO_ADRMAP = 32 
UV_STATUS_INFO = 33 
UV_STATUS_NO_MEM_ACCESS = 34 
UV_STATUS_FLASH_DOWNLOAD = 35 
UV_STATUS_BUILDING = 36 
UV_STATUS_HARDWARE = 37 
UV_STATUS_SIMULATOR = 38 
UV_STATUS_BUFFER_TOO_SMALL = 39 
UV_STATUS_EVTR_FAILED = 40

# VTT_TYPE
VTT_void = 0 
VTT_bit = 1 
VTT_char = 2 
VTT_uchar = 3 
VTT_int = 4 
VTT_uint = 5 
VTT_short = 6 
VTT_ushort = 7 
VTT_long = 8 
VTT_ulong = 9 
VTT_float = 10 
VTT_double = 11 
VTT_ptr = 12
VTT_union = 13 
VTT_struct = 14 
VTT_func = 15
VTT_string = 16 
VTT_enum = 17 
VTT_field = 18 
VTT_int64 = 19 
VTT_uint64 = 20

VTT_TYPE_MAP = {
    VTT_void: 'Q',
    VTT_bit: "L",
    VTT_char: "c", 
    VTT_uchar: "B",
    VTT_int: "i", 
    VTT_uint: "I", 
    VTT_short: "h", 
    VTT_ushort: "H",
    VTT_long: "l", 
    VTT_ulong: "L", 
    VTT_float: "f", 
    VTT_double: "d", 
    VTT_ptr: "L",
    VTT_union: "unused", 
    VTT_struct: "unused", 
    VTT_func: "unused",
    VTT_string: "unused",
    VTT_enum: "unused",
    VTT_field: "unused",
    VTT_int64: "q", 
    VTT_uint64: "Q"
}


class VSET(object):
    """
    typedef struct tval  {
        VTT_TYPE         vType;   ///< Indicates the type of data in @a v
        union  {                 
            unsigned long     ul;   ///< #VTT_ulong
            signed char       sc;   ///< #VTT_char
            unsigned char     uc;   ///< #VTT_uchar
            signed short     i16;   ///< #VTT_short
            unsigned short   u16;   ///< #VTT_ushort
            signed long        l;   ///< #VTT_long
            int                i;   ///< #VTT_int
            xI64             i64;   ///< #VTT_int64
            xU64             u64;   ///< #VTT_uint64
            float              f;   ///< #VTT_float
            double             d;   ///< #VTT_double
        } v;                      ///< Data type of this union depends on @a vType
    } TVAL;

    typedef struct sstr  {    
        int               nLen;   ///< Length of name (including NULL terminator)
        char        szStr[256];   ///< NULL terminated name string
    } SSTR;

    typedef struct vset_t  {
        TVAL               val;   ///< Value of VTREG or register index
        SSTR               str;   ///< Name of VTREG or expression
    } VSET;
    """
    def __init__(self):
        pass

    def pack(self, val_type, val, sstr):
        b_sstr = sstr.encode("UTF-8")
        format_str = '<i{}i{}s'.format(VTT_TYPE_MAP[val_type], len(b_sstr))  # little endian
        self.packed_byte =  struct.pack(format_str, val_type, val, len(b_sstr), b_sstr)
        return self.packed_byte

    def unpack(self, data):
        """
        data: byte array
        """
        assert(len(data)>=8)
        val_type = struct.unpack('<I', data[:4])[0]
        val_size = struct.calcsize('<{}'.format(VTT_TYPE_MAP[val_type]))
        val = struct.unpack('<{}'.format(VTT_TYPE_MAP[val_type]), data[4: 4+val_size])[0]
        length = struct.unpack('<i', data[4+8:4+8+4])[0]
        sstr = data[4+8+4:-1].decode()
        return val_type, val, sstr

class AMEM(object):
    """
    typedef struct amem  {
        xU64             nAddr;   ///< Address to read / write
        UINT            nBytes;   ///< Number of bytes read / write
        xU64           ErrAddr;   ///< Unused
        UINT              nErr;   ///< Unused
        xUC8         aBytes[1];   ///< @a nBytes of data read or to be written
    } AMEM;
    """
    def __init__(self):
        pass

    def pack(self, nAddr, nBytes):
        format_str = '<QI'  # little endian
        self.packed_byte =  struct.pack(format_str, nAddr, nBytes)
        return self.packed_byte

    def unpack(self, data):
        """
        data: byte array
        """
        assert(len(data)>=24)
        nAddr, nBytes, ErrAddr, nErr = struct.unpack('<QIQI', data[:24])
        return nAddr, ErrAddr, nErr, data[24:]

class UVSOCK_CMD(object):
    """
    typedef struct _tag_UVSOCK_CMD  {
        UINT             m_nTotalLen;    unsigned integer, 32bit ///< Total message length (bytes)
        UV_OPERATION          m_eCmd;    unsigned integer, 32bit ///< Command code
        UINT               m_nBufLen;    unsigned integer, 32bit ///< Length of Data Section (bytes)
        xU64                  cycles;    unsigned integer, 64bit ///< Cycle value (Simulation mode only)
        double                tStamp;    double, 64bit           ///< time-stamp (Simulation mode only)
        UINT                    m_Id;    unsigned integer, 32bit ///< Reserved
        UVSOCK_CMD_DATA         data;    ///< Data Section (Command code dependent data)
    } UVSOCK_CMD;
    """

    def __init__(self, m_eCmd, data=b''):
        self.m_eCmd, self.data = m_eCmd, data
        self.m_nTotalLen = 32 + len(self.data)
        self.m_nBufLen = len(self.data)
        self.m_cycles, self.m_tStamp, self.m_Id = 0, 0, 0

        self.vset = VSET()
        self.amem = AMEM()

    def pack(self):
        format_str = '<3IQdI{}s'.format(self.m_nBufLen)  # little endian
        self.packed_byte =  struct.pack(format_str, self.m_nTotalLen, self.m_eCmd, self.m_nBufLen, \
            self.m_cycles, self.m_tStamp, self.m_Id, self.data)
        return self.packed_byte
    
    def unpack(self, data):
        """
        data: byte array
        """
        assert(len(data)>=(32+8))
        m_nTotalLen, m_eCmd, m_nBufLen, m_cycles, m_tStamp, m_Id, r_cmd, r_status= struct.unpack('<3IQd3I', data[:32+8])
        m_data = data[32+8:]
        return m_nTotalLen, m_eCmd, m_nBufLen, m_cycles, m_tStamp, m_Id, r_cmd, r_status, m_data

    def retrive_version(self, data):
        m_nTotalLen, m_eCmd, m_nBufLen, m_cycles, m_tStamp, m_Id, r_cmd, r_status,  m_data = self.unpack(data)
        version = m_data.hex()
        return r_status, version

    def retrive_expression(self, data):
        m_nTotalLen, m_eCmd, m_nBufLen, m_cycles, m_tStamp, m_Id, r_cmd, r_status,  m_data= self.unpack(data)
        val_type, val, sstr = self.vset.unpack(m_data)
        return r_status, val_type, val, sstr

    def retrive_mem_data(self, data):
        m_nTotalLen, m_eCmd, m_nBufLen, m_cycles, m_tStamp, m_Id, r_cmd, r_status,  m_data = self.unpack(data)
        nAddr, ErrAddr, nErr, r_data= self.amem.unpack(m_data)
        return r_status, nAddr, ErrAddr, nErr, r_data


if __name__ == "__main__":
    formatter = UVSOCK_CMD(m_eCmd=1, data=b'')  
    d = formatter.pack()
    print(len(d))
    print(d.hex())
    print(" ".join([hex(s) for s in d]))