/*
** EPITECH PROJECT, 2021
** my_str_cmp
** File description:
** |
*/

#include <stdbool.h>

int my_strlen(char const *str);

int my_strcmp(char const *s1, char const *s2)
{
    if (my_strlen(s1) != my_strlen(s2))
        return false;
    for (int i = 0; s1[i] != '\0'; i++)
        if (s1[i] != s2[i])
            return false;
    return true;
}
