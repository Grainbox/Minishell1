/*
** EPITECH PROJECT, 2022
** B-PSU-101-REN-1-1-minishell1-tom.daniel
** File description:
** commands
*/

#include "my.h"
#include <stdbool.h>

void display_env(char **env)
{
    int i = 0;

    while (env[i]) {
        my_printf("%s\n", env[i]);
        i++;
    }
}

int commands(char *command, char **env)
{
    if (my_strcmp(command, "exit") == true) {
        return 1;
    }
    if (my_strcmp(command, "env") == true) {
        display_env(env);
        return 2;
    }
    return 0;
}
