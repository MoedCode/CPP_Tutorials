#include  "header_b.h"
#include <cstdarg>
#include <cstring>
#include <stdarg.h>
const char* cstrJoin(int count, ...)
{
    va_list args;
    static char buffer[500];  // Static buffer to hold the result
    buffer[0] = '\0';         // Initialize the buffer with an empty string

    va_start(args, count);  // Initialize the va_list

    for (int i = 0; i < count; i++)
    {

        const char* str = va_arg(args, const char*);  // Get the next string
        strcat(buffer, str);  // Append the string to the buffer
    }

    va_end(args);  // Clean up the va_list

    return buffer;
}
