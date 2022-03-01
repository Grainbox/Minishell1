/*
** EPITECH PROJECT, 2021
** My_Compute_Square_Root
** File description:
** racine carré
*/

int my_compute_power_rec(int nb, int p);

int my_compute_square_root(int nb)
{
    int i = 0;
    int result = 0;

    while (result <= nb) {
        result = my_compute_power_rec(i, 2);
        i++;
    }
    return (i - 2);
}
