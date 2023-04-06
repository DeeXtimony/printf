#include<main.h>

/**

* print_unsigned - Prints an unsigned integer
* @args: List of arguments to extract the integer to be printed
* @buffer: Buffer array used for printing
* @flags: Flags that affect the printing behavior
* @width: Minimum width of the printed integer
* @precision: Minimum number of digits to be printed
* @size: Size specifier (e.g. 'l' for long)
* This function prints an unsigned integer
* width, precision, and size.
*/
int print_unsigned(va_list args, char buffer[],
                   int flags, int width, int precision, int size)
{
    int i = BUFF_SIZE - 2;
    unsigned long int num = va_arg(args, unsigned long int);
    num = convert_size_unsgnd(num, size);

    if (num == 0) {
        buffer[i--] = '0';
    }

    buffer[BUFF_SIZE - 1] = '\0';
    while (num > 0) {
        buffer[i--] = (num % 10) + '0';
        num /= 10;
    }

    i++;

    switch (flags) {
        case F_PLUS:
            buffer[--i] = '+';
            break;
        case F_SPACE:
            buffer[--i] = ' ';
            break;
        case F_ZERO:
            buffer[--i] = '0';
            break;
        default:
            break;
    }

    return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}

/************* PRINTING UNSIGNED NUMBER IN OCTAL  ****************/
/**
 * print_octal - This  Print an unsigned number in octal notation
 * @args: Listing  of all arguments
 * @buffer: Buffering array to handle print
 * @flags: Calculating active flags
 * @width: Width specification
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_octal(va_list args, char buffer[],
               int flags, int width, int precision, int size)
{
    int i = BUFF_SIZE - 2;
    unsigned long int num = va_arg(args, unsigned long int);
    unsigned long int init_num = num;

    num = convert_size_unsgnd(num, size);

    if (num == 0) {
        buffer[i--] = '0';
    }

    buffer[BUFF_SIZE - 1] = '\0';
    while (num > 0) {
        buffer[i--] = (num % 8) + '0';
        num /= 8;
    }

    if (flags & F_HASH && init_num != 0) {
        buffer[i--] = '0';
    }

    i++;

    switch (flags) {
        case F_PLUS:
            buffer[--i] = '+';
            break;
        case F_SPACE:
            buffer[--i] = ' ';
            break;
        case F_ZERO:
            buffer[--i] = '0';
            break;
        default:
            break;
    }

    return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}

/**
* print_hexadecimal - Prints an unsigned number in hexadecimal notation
* @args: List of arguments containing the unsigned number to be printed
* @buffer: Buffer array used for printing
* @flags: Flags that affect the printing behavior
* @width: Minimum width of the printed number 
* @precision: Minimum number of digits to be printed 
* @size: Size specifier (e.g. 'l' for long)
*/

int print_hexadecimal(va_list args, char buffer[],int flags, int width, int precision, int size)
{
    return (print_hexa(args, "0123456789abcdef", buffer,flags, 'x', )

}



/**

* print_hexa - Prints a hexadecimal number in lower or upper case
* @types: List of arguments containing the hexadecimal number to be printed
* @map_to: Array of values used to map the number to either lower or upper case letters
* @buffer: Buffer array used for printing
* @flags: Flags that affect the printing behavior
* @flag_ch: Character for flag 
* @width: Minimum width of the printed number
* @precision: Minimum number of digits to be printed 
* @size: Size specifier (e.g. 'l' for long)
*/


int print_hexa(va_list types, char map_to[], char buffer[],
int flags, char flag_ch, int width, int precision, int size)
{
int i = BUFF_SIZE - 2;
unsigned long int num = va_arg(types, unsigned long int);
unsigned long int original_num = num;
UNUSED(width);
 num = convert_size_unsgnd(num, size);

 if (num == 0)
         buffer[i--] = '0';

 buffer[BUFF_SIZE - 1] = '\0';

 while (num > 0)
 {
         buffer[i--] = map_to[num % 16];
         num /= 16;
 }

 switch (flags & F_HASH)
 {
         case F_HASH:
                 if (original_num != 0)
                 {
                         buffer[i--] = flag_ch;
                         buffer[i--] = '0';
                 }
                 break;
 }

 i++;

 return (write_unsgnd(0, i, buffer, flags, width, precision, size));
