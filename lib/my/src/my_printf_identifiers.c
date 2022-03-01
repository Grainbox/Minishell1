/*
** EPITECH PROJECT, 2021
** my_printf
** File description:
** printf_identifiers
*/

#include "my.h"
#include "my_printf.h"
#include <limits.h>
#include <stdarg.h>

void printf_ident3(char *str, int *i, va_list args)
{
    if (str[*i] == '%' && str[*i + 1] == 'l') {
        my_put_long_nbr(va_arg(args, long long));
        *i += 2;
    }
    if (str[*i] == '%' && str[*i + 1] == 'p') {
        convert_long_to_base(va_arg(args, long long), 16, str[*i + 1]);
        *i += 2;
    }
}

void printf_ident2(char *str, int *i, va_list args)
{
    int number = 0;

    if (str[*i] == '%' && str[*i + 1] == 'o') {
        number = va_arg(args, int);
        if (number < 8)
            my_put_nbr(number);
        else
            convert_to_base(number, 8, str[*i + 1]);
        *i += 2;
    }
    if (str[*i] == '%' && str[*i + 1] == '%') {
        my_putchar('%');
        *i += 2;
    }
    if (str[*i] == '%' && str[*i + 1] == 'b') {
        convert_to_base(va_arg(args, int), 2, str[*i + 1]);
        *i += 2;
    }
    hexa_ident(args, str, i);
    printf_ident3(str, i, args);
}

void unsigned_numbers(long number)
{
    int size = 0;

    if (number >= 0)
        my_put_long_nbr(number);
    else {
        my_put_long_nbr(LONG_MAX + number);
    }
}

void printf_ident(char *str, int *i, va_list args)
{
    if (str[*i] == '%' && (str[*i + 1] == 'd' || str[*i + 1] == 'i')) {
        my_put_nbr(va_arg(args, int));
        *i += 2;
    }
    if (str[*i] == '%' && (str[*i + 1] == 's' || str[*i + 1] == 'S')) {
        my_putstr(va_arg(args, char *));
        *i += 2;
    }
    if (str[*i] == '%' && str[*i + 1] == 'c') {
        my_putchar(va_arg(args, int));
        *i += 2;
    }
    if (str[*i] == '%' && str[*i + 1] == 'u') {
        unsigned_numbers(va_arg(args, long));
        *i += 2;
    }
    printf_ident2(str, i, args);
    printf_flags(str, i, args);
}
