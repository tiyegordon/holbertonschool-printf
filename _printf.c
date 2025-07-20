#include "main.h"
#include <stdarg.h>

#include "main.h"

/**
* print_number - Recursively prints an integer using _putchar
* @n: The integer to print
* Return: Number of characters printed
*/
int print_number(int n)
{
int count = 0;

/* Special case: INT_MIN (-2147483648) */
if (n == -2147483648)
{
count += _putchar('-');
count += _putchar('2');  /* Manually printing '2' */
n = 147483648;  /* Remaining part to print */
}
else if (n < 0)
{
_putchar('-');
count++;
n = -n;
}

if (n / 10)
count += print_number(n / 10);

_putchar((n % 10) + '0');
count++;

return (count);
}

/**
* handle_specifier - Handles format specifiers in _printf
* @format: The format specifier
* @args: The va_list of arguments
* Return: Number of characters printed
*/
int handle_specifier(char format, va_list args)
{
int count = 0;

if (format == '%')
count += _putchar('%');
else if (format == 'd' || format == 'i')
count += print_number(va_arg(args, int));
else if (format == 'c')
count += _putchar(va_arg(args, int));
else if (format == 's')
{
char *str = va_arg(args, char *);
if (!str)
str = "(null)";
while (*str)
{
count += _putchar(*str);
str++;
}
}
else
{
count += _putchar('%');
count += _putchar(format);
}
return (count);
}

/**
* _printf - Custom printf function
* @format: Format string
* Return: Number of characters printed
*/
int _printf(const char *format, ...)
{
va_list args;
int count = 0;

if (!format)
return (-1);

va_start(args, format);

while (*format)
{
if (*format == '%')
{
format++;
if (*format == '\0')  /* Handle case where % is at end */
return (-1);
count += handle_specifier(*format, args);
}
else
count += _putchar(*format);

format++;
}

va_end(args);
return (count);
}

/**
* print_percent - Prints the '%' character
* @args: The va_list (not used here, but required for compatibility)
* Return: Number of characters printed (always 1 for '%')
*/
int print_percent(va_list args)
{
(void)args;
return (_putchar('%'));
}

/**
* print_int - Prints an integer using print_number
* @args: The va_list of arguments
* Return: Number of characters printed
*/
int print_int(va_list args)
{
return (print_number(va_arg(args, int)));
}
