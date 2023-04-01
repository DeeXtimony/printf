#include "main.h"

/************************* PRINT UNSIGNED NUMBER *************************/
/**
 * print_unsigned - Prints an unsigned number
 * @args: List of arguments
 * @buffer: Buffer array to handle print
 * @flags: Calculates active flags
 * @width: Width specification
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed.
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

/************* PRINT UNSIGNED NUMBER IN OCTAL  ****************/
/**
 * print_octal - Prints an unsigned number in octal notation
 * @args: List of arguments
 * @buffer: Buffer array to handle print
 * @flags: Calculates active flags
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

/************** PRINT UNSIGNED NUMBER IN HEXADECIMAL **************/
/**
 * print_hexadecimal - Prints an unsigned number in hexadecimal notation
 * @args: List of arguments
 * @buffer: Buffer array to handle print
 * @flags: Calculates active flags
 * @width: Width specification
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_hexadecimal(va_list args, char buffer[],int flags, int width, int precision, int size)
{
    return (print_hexa(args, "0123456789abcdef", buffer,flags, 'x', width)
}
i want you to change the conditional statement(if) to a switch case statement, i want you to change the for loop to a while loop statement, i want you to change the variable  name to somthing else and lastly i want you to change the comment description to something more explanatory














/************** PRINT HEXADECIMAL NUM IN LOWER OR UPPER ************/
/

print_hexa - Prints a hexadecimal number in lower or upper case

@types: List of arguments

@map_to: Array of values to map the number to

@buffer: Buffer array to handle print

@flags: Calculates active flags

@flag_ch: Character for flag

@width: Width specifier
@precision: Precision specifier

@size: Size specifier

Return: Number of chars printed
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
