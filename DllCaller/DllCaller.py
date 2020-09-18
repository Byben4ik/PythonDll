from ctypes import *

lib = cdll.LoadLibrary("HelloWorldDll.dll")

function_c = c_short(1)

handle_c = c_short(2)
lp_c = c_int(3)
p_c = c_short(4)

buffer = [0x0, 0x1, 0x2, 0x3, 0x4, 0x5, 0x6, 0x7, 0x8, 0x9, 0x0A, 0x0B]
bufferSize = len(buffer)
bufferSize_c = c_short(bufferSize)
buffer_c = (c_byte * bufferSize)(*buffer)

s = 'Hello, World'
str_c = c_wchar_p(s)

result = lib.printArgs(function_c, pointer(handle_c), pointer(lp_c), pointer(p_c), buffer_c, bufferSize_c, str_c)

print('\nResult from DLL: ' + str(result))