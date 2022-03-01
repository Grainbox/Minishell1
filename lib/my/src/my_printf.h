/*
** EPITECH PROJECT, 2021
** my_printf
** File description:
** my_printf
*/

#include <stdarg.h>

#ifndef MY_PRINTF_H_
    #define MY_PRINTF_H_

    void printf_ident(char *str, int *i, va_list args);

    int my_put_long_nbr(long nb);

    void convert_to_base(int number, int base, char letter);

    void hexa_ident(va_list args, char *str, int *i);

    void convert_long_to_base(long long number, int base, char letter);

    void printf_flags(char *str, int *i, va_list args);

#endif
