/*
** EPITECH PROJECT, 2021
** My_Getnbr
** File description:
** get nbr of string
*/

#include <stdlib.h>

int size_str(char const *str)
{
    int i = 0;
    while (str[i] != '\0') {
        i++;
    }
    return i;
}

void num_array_style(char const *str, char *num_str, int *i, int *l)
{
    if (str[*i - 1] == '-') {
        num_str[*l] = str[*i - 1];
        ++(*l);
    }
}

char *create_num_array(char const *str)
{
    int i = 0;
    int l = 0;
    char *num_str;
    num_str = malloc(sizeof(char) * size_str(str));
    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] >= '0' && str[i] <= '9') {
            num_array_style(str, num_str, &i, &l);
            num_str[l] = str[i];
            l++;
        } else if (l > 0) {
            num_str[l] = '\0';
            return (num_str);
        }
    }
    num_str[l] = '\0';
    return (num_str);
}

int convert(char *num_str, int size)
{
    int end = 0;
    int multi = 1;
    int number = 0;
    long number_lg = 0;

    for (int i = size; i >= end; i--) {
        if (num_str[0] == '-')
            end = 1;
        number = num_str[i] - 48;
        number_lg += number * multi;
        multi *= 10;
    }
    number = number_lg;
    if (number_lg > number)
        return 0;
    else {
        if (num_str[0] == '-')
            number *= -1;
        return (number);
    }
}

int my_getnbr(char const *str)
{
    char *num_str;
    int size = 0;
    int number = 0;

    num_str = create_num_array(str);
    size = size_str(num_str);
    size--;
    number = convert(num_str, size);
    return (number);
}
