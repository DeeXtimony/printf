#include "main.h"

/**

* print_character - Prints a single character
* @args: List of arguments containing the character
* @buffer: Buffer array used for printing
* @flags: Flags that affect the printing behavior
* @width: Minimum width of the printed character 
* @precision: Not used in this function
* @size: Size specifier
*/

int print_character(va_list args, char buffer[],
int flags, int width, int precision, int size)
{
char c = va_arg(args, int);
return (handle_write_char(c, buffer, flags, width, precision, size));
}

/**
* print_string - Prints a string
* @args: List of arguments containing the string 
* @buffer: Buffer array used for printing
* @flags: Flags that affect the printing behavior 
* @width: Minimum width of the printed string 
* @precision: Maximum number of characters to be printed 
* @size: Size specifier
*/

int print_string(va_list args, char buffer[],
int flags, int width, int precision, int size)
{
int length = 0, i;
char *str = va_arg(args, char *);

UNUSED(buffer);
UNUSED(flags);
UNUSED(width);
UNUSED(precision);
UNUSED(size);

if (str == NULL)
{
str = "(null)";
if (precision >= 6)
str = " ";
}

while (str[length] != '\0')
length++;

switch (precision >= 0 && precision < length)
{
case 1:
length = precision;
break;
default:
break;
}

if (width > length)
{
if (flags & F_MINUS)
{
write(1, &str[0], length);
for (i = width - length; i > 0; i--)
write(1, " ", 1);
return (width);
}
else
{
for (i = width - length; i > 0; i--)
write(1, " ", 1);
write(1, &str[0], length);
return (width);
}
}

return (write(1, str, length));
}
/**

* print_percent - Prints a percent sign
* @args: List of arguments
* @buffer: Buffer array used for printing
* @flags: Flags that affect the printing behavior
* @width: Minimum width of the printed percent sign
* @precision: Minimum number of characters to be printed
* @length: Length modifier
*/

int print_percent(va_list args, char buffer[], int flags, int width,
int precision, int length)
{
UNUSED(args);
UNUSED(flags);
UNUSED(width);
UNUSED(precision);
UNUSED(length);
return (write(1, "%", 1));
}
/**

* print_int - Printing an integer
* @args: List of arguments containing the integer
* @buffer: Buffer array used for printing
* @flags: Flags that affect the printing behavior
* @width: Minimum width of the printed integer
* @precision: Minimum number of digits to be printed 
* @length: Length modifier 

*/

int print_int(va_list args, char buffer[], int flags, int width,
int precision, int length)
{
int i = BUFF_SIZE - 2;
int is_negative = 0;
long int num = va_arg(args, long int);
unsigned long int u_num;

num = convert_length_modifier(num, length);

if (num == 0)
buffer[i--] = '0';

buffer[BUFF_SIZE - 1] = '\0';
u_num = (unsigned long int) num;

if (num < 0) {
u_num = (unsigned long int) (-num);
is_negative = 1;
}

while (u_num > 0) {
buffer[i--] = (u_num % 10) + '0';
u_num /= 10;
}

i++;

return (write_number(is_negative, i, buffer, flags, width, precision, length));
}
