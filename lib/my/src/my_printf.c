/*
** EPITECH PROJECT, 2021
** my_printf
** File description:
** my_printf
*/

#include "my.h"
#include "my_printf.h"
#include <stdarg.h>
#include <stdio.h>

void my_printf(char *str, ...)
{
    va_list args;
    int i = 0;
    int size = my_strlen(str);
    va_start(args, str);
    for (i = 0; str[i] != '\0'; i++) {
        printf_ident(str, &i, args);
        if (str[i] == '%')
            printf_ident(str, &i, args);
        if (str[i] == '\0')
            break;
        my_putchar(str[i]);
    }
    va_end(args);
}
