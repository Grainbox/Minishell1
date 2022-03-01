/*
** EPITECH PROJECT, 2021
** my_printf
** File description:
** my_printf_base_process
*/

#include "my.h"
#include "my_printf.h"
#include <limits.h>
#include <stdarg.h>

char complete_letters(int number, char letter, int base, char hexa)
{
    if (number >= 10 && base == 16 && hexa == 'x')
        letter = number + 87;
    if (number >= 10 && base == 16 && hexa == 'X')
        letter = number + 55;
    if ((number == 2 && base == 2) || (number == 16 && base == 16)) {
        letter = '0';
        my_putchar('1');
    }
    if (number == 8 && base == 8) {
        letter = '0';
        my_putchar('1');
    }
    return letter;
}

void convert_to_base(int number, int base, char letter)
{
    int count = 0;
    int result = number * base;
    int modul_result = number;
    int j = 0;
    char str[number];

    while (number > base) {
        number /= base;
        count++;
    }
    for (int i = 0; i < count; i++, j++) {
        result /= base;
        modul_result = result % base;
        str[j] = modul_result + '0';
        str[j] = complete_letters(modul_result, str[j], base, letter);
    }
    str[j] = number + '0';
    str[j] = complete_letters(number, str[j], base, letter);
    str[j + 1] = '\0';
    my_putstr(my_revstr(str));
}

char complete_long_letters(int number, char letter, int base, char hexa)
{
    if (number >= 10 && base == 16 && hexa == 'x')
        letter = number + 87;
    if (number >= 10 && base == 16 && hexa == 'X')
        letter = number + 55;
    return letter;
}

void convert_long_to_base(long long number, int base, char letter)
{
    int count = 0;
    long long result = number * base;
    long long modul_result = number;
    int j = 0;
    char str[1000];
    while (number > base) {
        number /= base;
        count++;
    }
    for (int i = 0; i < count; i++, j++) {
        result /= base;
        modul_result = result % base;
        str[j] = modul_result + '0';
        str[j] = complete_letters(modul_result, str[j], base, letter);
    }
    str[j] = number + '0';
    str[j] = complete_letters(number, str[j], base, letter);
    str[j + 1] = '\0';
    my_putstr(my_revstr(str));
}

void hexa_ident(va_list args, char *str, int *i)
{
    int number = 0;

    if (str[*i] == '%' && (str[*i + 1] == 'x' || str[*i + 1] == 'X')) {
        number = va_arg(args, int);
        if (number >= 10 && number < 16 && str[*i + 1] == 'x')
            my_putchar(number + 87);
        else if (number >= 10 && number < 16 && str[*i + 1] == 'X')
            my_putchar(number + 55);
        else
            convert_to_base(number, 16, str[*i + 1]);
        *i += 2;
    }
}
