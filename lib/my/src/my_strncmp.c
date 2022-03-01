/*
** EPITECH PROJECT, 2021
** my_strncmp
** File description:
** |
*/

#include <stdbool.h>

int my_strncmp(char const *s1, char const *s2, int n)
{
    for (int i = 0; i < n; i++)
        if (s1[i] != s2[i])
            return false;
    return true;
}
