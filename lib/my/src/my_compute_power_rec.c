/*
** EPITECH PROJECT, 2021
** My_Compute_Power_Rec
** File description:
** puissance recursive
*/

int my_compute_power_rec(int nb, int p)
{
    if (p == 0)
        return 1;
    if (p > 0)
        return (nb * my_compute_power_rec(nb , p -= 1));
    else
        return 0;
}
