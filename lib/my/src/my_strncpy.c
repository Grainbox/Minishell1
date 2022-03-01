/*
** EPITECH PROJECT, 2021
** My_strncpy
** File description:
** |
*/

char *my_strncpy(char *dest, char const *src, int n)
{
    int len = 0;
    int i = 0;

    while (src[len] != '\0')
        len++;
    while (i != len) {
        dest[i] = src[i];
        i++;
    }
    if (n > len)
        dest[len + 1] = '\0';
    else
        dest[n + 1] = '\0';
    return (dest);
}
