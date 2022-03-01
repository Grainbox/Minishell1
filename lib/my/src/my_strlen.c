/*
** EPITECH PROJECT, 2021
** My_Strlen
** File description:
** |
*/

void my_putchar(char c);

int my_strlen(char const *str)
{
    int count = 0;
    int i = 0;

    while (str[i] != '\0') {
        count++;
        i++;
    }
    return (count);
}
