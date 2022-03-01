/*
** EPITECH PROJECT, 2021
** My_Swap
** File description:
** |
*/

void my_putchar(char c);

void my_swap(int *a, int *b)
{
    int num1 = *a;
    int num2 = *b;

    *a = num2;
    *b = num1;
}
