/*
** EPITECH PROJECT, 2021
** Project_Template
** File description:
** my_to_number
*/

void number_to_string(char *str, int number)
{
    int to_number = number;
    int gap = 0;
    int count = 0;

    while (to_number > 0) {
        to_number /= 10;
        count++;
    }
    for (int i = 0; i < count; i++) {
        gap = number % 10;
        number /= 10;
        str[count - (i + 1)] = gap + '0';
    }
    str[count] = '\0';
}
