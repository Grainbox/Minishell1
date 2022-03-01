/*
** EPITECH PROJECT, 2021
** My_Put_NBR
** File description:
** |
*/

void my_putchar(char c);

int my_put_nbr(int nb)
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
