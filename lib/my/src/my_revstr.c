/*
** EPITECH PROJECT, 2021
** my_revstr
** File description:
** |
*/

char *my_strcpy(char *dest, char const *src);

char *my_revstr(char *str)
{
    int len = 0;
    int i = 0;
    int max_len = 0;

    while (str[len] != '\0')
        len++;
    len--;
    max_len = len;
    char dest[len];
    while (i <= len) {
        dest[i] = str[max_len];
        max_len--;
        i++;
    }
    str = my_strcpy(str, dest);
    str[len + 1] = '\0';
    return (str);
}
