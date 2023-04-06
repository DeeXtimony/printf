#include <main.h>
/**

* get_precision - Calculates the precision to be used
* @format: Formatted string in which to print the arguments.
* @i: Pointer to the current index in the format string.
* @list: List of arguments.
*/

int get_precision(const char *format, int *i, va_list list)
{
        int curr_i = *i + 1;
        int precision = -1;

        switch (format[curr_i]) {
                case '.':
                        precision = 0;
                        break;
                default:
                        return precision;
        }

        
        while (format[++curr_i] != '\0') {
                switch (format[curr_i]) {
                        case '*':
                                curr_i++;
                                precision = va_arg(list, int);
                                goto end_loop;
                        default:
                                if (is_digit(format[curr_i])) {
                                        precision *= 10;
                                        precision += format[curr_i] - '0';
                                } else {
                                        goto end_loop;
                                }
                }
        }

        end_loop:
        *i = curr_i - 1;
        return precision;
}
