#include "main.h"
/**

* get_flags - Calculates active flags based on format string
* @format: Formatted string to print the arguments
* @i: Index of the current format specifier
*/

int get_flags(const char *format, int *i)
{
       
        int j, curr_i;
        int flags = 0;
        const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
        const int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

        curr_i = *i + 1;
        while (format[curr_i] != '\0') {
            switch(format[curr_i]) {
                case '-':
                    flags |= F_MINUS;
                    break;
                case '+':
                    flags |= F_PLUS;
                    break;
                case '0':
                    flags |= F_ZERO;
                    break;
                case '#':
                    flags |= F_HASH;
                    break;
                case ' ':
                    flags |= F_SPACE;
                    break;
                default:
                    break;
            }
            curr_i++;
        }

        *i = curr_i - 1;

        return (flags);
}
