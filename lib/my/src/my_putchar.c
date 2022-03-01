/*
** EPITECH PROJECT, 2021
** My_Print_Alpha
** File description:
** my_putchar for my print alpha
*/
#include<unistd.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}
