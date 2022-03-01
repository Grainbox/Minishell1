/*
** EPITECH PROJECT, 2021
** library
** File description:
** put_error
*/

#include "my.h"
#include <unistd.h>

void my_puterror(char *str)
{
    int size = my_strlen(str);
    write(2, str, size);
}
