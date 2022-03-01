/*
** EPITECH PROJECT, 2021
** my_printf
** File description:
** my_printf_flags
*/

#include "my.h"
#include "my_printf.h"
#include <stdarg.h>

void ashtag_hexa_flag(char *str, int *i, int number)
{
    if (number < 10 && number != 0)
        my_put_nbr(number);
    if (number >= 10 && number < 16 && str[*i + 2] == 'x')
        my_putchar(number + 87);
    else if (number >= 10 && number < 16 && str[*i + 2] == 'X')
        my_putchar(number + 55);
    else
        convert_to_base(number, 16, str[*i + 2]);
}

void printf_flags2(char *str, int *i, va_list args)
{
    int number = 0;

    number = va_arg(args, int);
    if (number != 0 && str[*i + 2] == 'x')
        my_putstr("0x");
    else if (number != 0 && str[*i + 2] == 'X')
        my_putstr("0X");
    ashtag_hexa_flag(str, i, number);
    *i += 3;
}

void printf_flags(char *str, int *i, va_list args)
{
    int number = 0;

    if (str[*i] == '%' && str[*i + 1] == '#' && str[*i + 2] == 'o') {
        number = va_arg(args, int);
        if (number != 0)
            my_putchar('0');
        if (number < 8)
            my_put_nbr(number);
        else
            convert_to_base(number, 8, str[*i + 2]);
        *i += 3;
    }
    if (str[*i] == '%' && str[*i + 1] == '#') {
        if (str[*i + 2] == 'x' || str[*i + 2] == 'X') {
            printf_flags2(str, i, args);
        }
    }
}
