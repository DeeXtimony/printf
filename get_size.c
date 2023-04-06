#include "main.h"

/**

* get_size - Calculates the size to cast the argument
* @format: Formatted string to print the arguments
* @i: Index of the current format specifier
*/

int get_size(const char *format, int *i)
{
        int curr_i = *i + 1;
        int size = 0;

        switch (format[curr_i]) {
            case 'l':
                size = S_LONG;
                break;
            case 'h':
                size = S_SHORT;
                break;
            default:
                break;
        }

        if (size == 0) {
            *i = curr_i - 1;
        } else {
            *i = curr_i;
        }

        return size;
}
