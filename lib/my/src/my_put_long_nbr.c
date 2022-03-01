/*
** EPITECH PROJECT, 2021
** my_printf
** File description:
** my_put_ong_number
*/

#include "my.h"

int my_put_long_nbr(long long nb)
{
    if (nb < 0) {
        if (nb == -2147483648) {
            my_putchar('-');
            my_putchar('2');
            nb = -147483648;
            nb = nb * -1;
        } else {
            my_putchar('-');
            nb = nb * -1;
        }
    }
    if (nb >= 10) {
        my_put_nbr(nb / 10);
        my_put_nbr(nb % 10);
        return (0);
    } else {
        my_putchar(nb + 48);
        return (0);
    }
}
