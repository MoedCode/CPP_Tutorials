#!/usr/bin/env python3
import ctypes
import os

# Load the shared library
if os.name == 'nt':  # Windows
    str_join = ctypes.CDLL('./x2_cstring.dll')
else:  # Linux/Mac
    str_join = ctypes.CDLL('./x2_cstring.so')

# Define the return type and argument types for the C function
str_join.c_strjoin.restype = ctypes.c_char_p  # The function returns a char* (string)
str_join.c_strjoin.argtypes = [ctypes.c_char_p, ctypes.c_char_p]  # The function takes two char* arguments

# Define the free_memory function (if added to the C code)
if hasattr(str_join, 'free_memory'):
    str_join.free_memory.argtypes = [ctypes.c_char_p]  # The function takes a char* argument

# Input strings (must be bytes-like objects in Python)
str0 = b"first_string"  # Encode as bytes
str1 = b"second_string"  # Encode as bytes

# Call the C function
buff = str_join.c_strjoin(str0, str1)

# Decode the result from bytes to string
result_str = buff.decode('utf-8')
print("Result from C function:", result_str)

# Free the memory allocated by the C function (if free_memory is implemented)
if hasattr(str_join, 'free_memory'):
    str_join.free_memory(buff)
else:
    print("Warning: free_memory function not found in the shared library. Memory may not be freed.")