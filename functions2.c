#include "main.h"

/**

* print_pointer - Prints the value of a pointer variable
* @types: List of arguments containing the pointer variable to be printed
* @buffer: Buffer array used for printing
* @flags: Flags that affect the printing behavior 
* @width: Minimum width of the printed pointer 
* @precision: Minimum number of digits to be printed 
* @size: Size specifier 
*/

int print_pointer(va_list types, char buffer[],
        int flags, int width, int precision, int size)
{
    char extra_c = 0, padd = ' ';
    int ind = BUFF_SIZE - 2, length = 2, padd_start = 1; /* length=2, for '0x' */
    unsigned long num_addrs;
    char map_to[] = "0123456789abcdef";
    void *addrs = va_arg(types, void *);

    UNUSED(width);
    UNUSED(size);

    if (addrs == NULL)
        return (write(1, "(nil)", 5));

    buffer[BUFF_SIZE - 1] = '\0';
    UNUSED(precision);

    num_addrs = (unsigned long)addrs;

    while (num_addrs > 0)
    {
        buffer[ind--] = map_to[num_addrs % 16];
        num_addrs /= 16;
        length++;
    }

    switch (flags)
    {
        case F_ZERO:
            if (!(flags & F_MINUS))
                padd = '0';
            break;
        case F_PLUS:
            extra_c = '+';
            length++;
            break;
        case F_SPACE:
            extra_c = ' ';
            length++;
            break;
    }

    ind++;

    
    return (write_pointer(buffer, ind, length,
            width, flags, padd, extra_c, padd_start));
}

/**

* print_non_printable - Prints ASCII codes in hexadecimal 
* @types: List of arguments in string
* @buffer: Buffer array used for printing
* @flags: Flags that affect the printing behavior 
* @width: Minimum width of the printed string 
* @precision: Maximum number of characters to be printed
* @size: Size specifier
*/

int print_non_printable(va_list types, char buffer[],
        int flags, int width, int precision, int size)
{
    int i = 0, offset = 0;
    char *input_str = va_arg(types, char *);

    UNUSED(flags);
    UNUSED(width);
    UNUSED(precision);
    UNUSED(size);

    if (input_str == NULL)
        return (write(1, "(null)", 6));

    while (input_str[i] != '\0')
    {
        if (is_printable(input_str[i]))
            buffer[i + offset] = input_str[i];
        else
            offset += append_hexa_code(input_str[i], buffer, i + offset);

        i++;
    }

    buffer[i + offset] = '\0';

    
    return (write(1, buffer, i + offset));
}
/**

* print_reverse_string - Prints a string in reverse order
* @types: List of arguments containing the string
* @buffer: Buffer array used for printing
* @flags: Flags that affect the printing behavior
* @width: Minimum width of the printed string
* @precision: Maximum number of characters 
* @size: Size specifier 
*/

int print_reverse(va_list types, char buffer[], int flags, int width, int precision, int size)
{
    char *str;
    int i, count = 0;

    UNUSED(buffer);
    UNUSED(flags);
    UNUSED(width);
    UNUSED(size);

    str = va_arg(types, char *);

    switch(str != NULL){
        case true:
            for (i = strlen(str) - 1; i >= 0; i--)
            {
                char c = str[i];
                write(1, &c, 1);
                count++;
            }
            break;
        case false:
            UNUSED(precision);
            str = ")Null(";
            for (i = strlen(str) - 1; i >= 0; i--)
            {
                char c = str[i];
                write(1, &c, 1);
                count++;
            }
            break;
    }

    return count;
}


int print_rot13string(va_list types, char buffer[], int flags, int width, int precision, int size)
{
    char x;
    char *str;
    unsigned int i, j;
    int count = 0;
    char in[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    char out[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

    str = va_arg(types, char *);

    UNUSED(buffer);
    UNUSED(flags);
    UNUSED(width);
    UNUSED(precision);
    UNUSED(size);

    str = (str == NULL) ? "(AHYY)" : str;

    for (i = 0; str[i]; i++)
    {
        for (j = 0; in[j]; j++)
        {
            if (in[j] == str[i])
            {
                x = out[j];
                write(1, &x, 1);
                count++;
                break;
            }
        }
        if (!in[j])
        {
            x = str[i];
            write(1, &x, 1);
            count++;
        }
    }

    return count;
}
