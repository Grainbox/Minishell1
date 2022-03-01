/*
** EPITECH PROJECT, 2021
** my_strncat
** File description:
** |
*/

char *my_strncat(char *dest, char const *src, int nb)
{
    int i = 0;
    int l = 0;

    while (dest[i] != '\0')
        i++;
    for (l = 0; l <= nb - 1; l++) {
        dest[i] = src[l];
        i++;
    }
    dest[i] = '\0';
    return (dest);
}
