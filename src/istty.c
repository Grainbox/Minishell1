/*
** EPITECH PROJECT, 2022
** B-PSU-101-REN-1-1-minishell1-tom.daniel
** File description:
** istty
*/

#include "my.h"
#include <unistd.h>
#include <signal.h>
#include <string.h>
#include <errno.h>
#include <sys/wait.h>
#include <stdlib.h>
#include "minishell.h"

int istty(char *buffer, char **env)
{
    int i = 0;

    read(STDIN_FILENO, buffer, 100);
    for (; buffer[i] != '\n'; i++);
    buffer[i] = '\0';
    if (commands(buffer, env) == 1)
        return 0;
    else
        exec_process(buffer, env);
    wait(NULL);
    return 0;
}
