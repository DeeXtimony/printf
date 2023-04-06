#include "main.h"
/**

* handle_write_char - Writes a given character to a buffer
* @c: The character to be written and printed.
* @buffer: The buffer array used for printing.
* @flags: The active flags for printing.
* @width: The width specifier used for printing.
* @precision: The precision specifier used for printing.
* @size: The size specifier used for printing.
*/
int handle_write_char(char c, char buffer[], int flags, int width, int precision, int size)
{
    int i = 0;
    char padd = ' ';

    UNUSED(precision);
    UNUSED(size);

    if (flags & F_ZERO)
        padd = '0';

    buffer[i++] = c;
    buffer[i] = '\0';

    if (width > 1)
    {
        buffer[BUFF_SIZE - 1] = '\0';
        for (i = 0; i < width - 1; i++)
            buffer[BUFF_SIZE - i - 2] = padd;
        if (flags & F_MINUS)
            return (write(1, &buffer[0], 1) + write(1, &buffer[BUFF_SIZE - i - 1], width - 1));
        else
            return (write(1, &buffer[BUFF_SIZE - i - 1], width - 1) + write(1, &buffer[0], 1));
    }
    return (write(1, &buffer[0], 1));
}

/**

* write_number - Writes a given number to a buffer and prints it.
* @is_negative: A flag indicating whether the number is negative or not.
* @ind: The index of the buffer at which to start writing.
* @buffer: The buffer array used for printing.
* @flags: The active flags for printing.
* @width: The width of the printed number.
* @precision: The precision specifier used for printing.
* @size: The size specifier used for printing.
*/

int write_number(int is_negative, int ind, char buffer[],
                 int flags, int width, int precision, int size)
{
    int length = BUFF_SIZE - ind - 1;
    char padd = ' ', extra_ch = 0;

    UNUSED(size);

    if ((flags & F_ZERO) && !(flags & F_MINUS))
        padd = '0';

    if (is_negative)
        extra_ch = '-';
    else if (flags & F_PLUS)
        extra_ch = '+';
    else if (flags & F_SPACE)
        extra_ch = ' ';

    return (write_num(ind, buffer, flags, width, precision,
                      length, padd, extra_ch));
}

/**

* write_num - Writes a given number to a buffer.
* @ind: The index at which the number starts on the buffer.
* @buffer: The buffer to which the number should be written.
* @flags: The flags to be applied while writing.
* @width: The width of the number to be written.
* @prec: The precision specifier to be applied
* @length: The length of the number to be written.
* @padd: The padding character to be used.
* @extra_c: An extra character to be appended to the output
*/

int write_num(int ind, char buffer[],
              int flags, int width, int prec,
              int length, char padd, char extra_c)
{
    int i, padd_start = 1;

    if (prec == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0' && width == 0)
        return (0); 

    if (prec == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0')
        buffer[ind] = padd = ' '; 

    if (prec > 0 && prec < length)
        padd = ' ';

    while (prec > length)
        buffer[--ind] = '0', length++;

    if (extra_c != 0)
        length++;

    if (width > length)
    {
        for (i = 1; i < width - length + 1; i++)
            buffer[i] = padd;

        buffer[i] = '\0';

        if (flags & F_MINUS && padd == ' ') 
        {
            if (extra_c)
                buffer[--ind] = extra_c;

            return (write(1, &buffer[ind], length) + write(1, &buffer[1], i - 1));
        }
        else if (!(flags & F_MINUS) && padd == ' ') 
        {
            if (extra_c)
                buffer[--ind] = extra_c;

            return (write(1, &buffer[1], i - 1) + write(1, &buffer[ind], length));
        }
        else if (!(flags & F_MINUS) && padd == '0') 
        {
            if (extra_c)
                buffer[--padd_start] = extra_c;

            return (write(1, &buffer[padd_start], i - padd_start) +
                    write(1, &buffer[ind], length - (1 - padd_start)));
        }
    }

    if (extra_c)

