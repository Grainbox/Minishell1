/*
** EPITECH PROJECT, 2022
** B-PSU-101-REN-1-1-minishell1-tom.daniel
** File description:
** error_handling
*/

#include "my.h"
#include <stdlib.h>

int error_handler(int argc, char **argv)
{
    if (argc != 1) {
        my_puterror("Wrong argument\n");
        return 84;
    }
    return 0;
}

void free_malloc(char **args, char *name)
{
    int i = 0;

    while (args[i] != NULL) {
        free(args[i]);
        i++;
    }
    free(name);
    free(args);
}
