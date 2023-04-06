#include "main.h"

/**

* is_printable - Determines whether a given character
* @c: The character to be evaluated.
*/

int is_printable(char c)
{
    switch (c) {
        case 32 ... 126:
            return 1;
        default:
            return 0;
    }
}

/**

* append_hexa_code - Appends the ASCII code of a character in hexadecimal format 
* @buffer: The array of characters to which the ASCII code 
* @i: The index at which to start appending.
*@ascii_code: The ASCII code of the character to be appended.
*/

int append_hexa_code(char ascii_code, char buffer[], int i)
{
    char map_to[] = "0123456789ABCDEF";
    
    if (ascii_code < 0)
        ascii_code *= -1;

    buffer[i++] = '\\';
    buffer[i++] = 'x';

    buffer[i++] = map_to[ascii_code / 16];
    buffer[i] = map_to[ascii_code % 16];
    return 3;
}

/**

* is_digit - Determines whether a given character is a digit or not.
* @c: The character to be evaluated.
*/

int is_digit(char c)
{
    switch (c) {
        case '0' ... '9':
            return 1;
        default:
            return 0;
    }
}

/**

* convert_size_number - Converts a given number to a specified data type of a certain size.
* @num: The number to be converted.
* @size: The size of the data type to which @num should be converted.

*/
long int convert_size_number(long int num, int size)
{
    switch (size) {
        case S_LONG:
            return num;
        case S_SHORT:
            return (short)num;
        default:
            return (int)num;
    }
}

/**
 * convert_size_unsgnd - Casts a number to the specified size
 * @num: Number to be casted
 * @size: Number indicating the type to be casted
 *
 * Return: Casted value of num
 */

unsigned long int convert_size_unsgnd(unsigned long int num, int size)
{
    switch (size) {
        case S_LONG:
            return num;
        case S_SHORT:
            return (unsigned short)num;
        default:
            return (unsigned int)num;
    }
}
