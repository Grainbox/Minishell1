/*
** EPITECH PROJECT, 2021
** my_strstr
** File description:
** my_strstr
*/

#include "my.h"
#include <stdlib.h>

char *my_strstr(char *str, char const *to_find)
{
    int i = 0;
    int l = 0;
    char *found = malloc(sizeof(char) * my_strlen(str));

    while (str[i] != '\0') {
        if (str[i] == to_find[l]) {
            found[l] = str[i];
            l++;
        } else if (l > 0) {
            found[l] = str[i];
            l++;
        }
        i++;
    }
    found[l] = '\0';
    return found;
}
