/*
** EPITECH PROJECT, 2021
** My_Isneg
** File description:
** |
*/

void my_putchar(char c);

int my_isneg(int n)
{
    if (n < 0)
        my_putchar(78);
    else
        my_putchar(80);
    my_putchar('\n');
}
