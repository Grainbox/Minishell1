/*
** EPITECH PROJECT, 2022
** B-PSU-101-REN-1-1-minishell1-tom.daniel
** File description:
** minishell
*/

#include "my.h"
#include <unistd.h>
#include <signal.h>
#include <string.h>
#include <errno.h>
#include <sys/wait.h>
#include <stdlib.h>
#include "minishell.h"

int feel_args2(int j, int i, char ***args, char *str)
{
    i++;
    int l = 0;
    for (; str[i] != '\0'; l++, i++) {
        if (str[i] == ' ')
            break;
        (*args)[j][l] = str[i];
    }
    (*args)[j][l] = '\0';
    return i;
}

int feel_args(char *str, char ***args, int *nb_arg)
{
    int i = 0;

    (*args)[0] = malloc(sizeof(char) * (my_strlen(str) + 1));
    while (str[i] != ' ' && str[i] != '\0') {
        (*args)[0][i] = str[i];
        i++;
    }
    (*args)[0][i] = '\0';
    if ((*nb_arg) == 0)
        return ++(*nb_arg);
    for (int j = 1; j <= (*nb_arg); j++) {
        (*args)[j] = malloc(sizeof(char) * my_strlen(str) + 1);
        i = feel_args2(j, i, args, str);
    }
    return (*nb_arg);
}

char *fill_name_args(char *arg, char ***args, int *nb_args, char **env)
{
    int i = 0;
    int l = 0;
    char *name = malloc(sizeof(char) * (my_strlen(arg) + 20));

    for (; arg[i] != '\0'; i++, l++) {
        if (arg[i] == ' ')
            break;
        name[l] = arg[i];
    }
    name[l] = '\0';
    if (get_path(env, name) != NULL)
        my_strcpy(name, get_path(env, name));
    for (; arg[i] != '\0'; i++)
        if (arg[i] == ' ')
            ++(*nb_args);
    (*args) = malloc(sizeof(char *) * ((*nb_args) + 2));
    feel_args(arg, args, nb_args);
    (*args)[(*nb_args) + 1] = NULL;
    return name;
}

int exec_process(char *command, char **env)
{
    char **args = NULL;
    int nb_args = 0;
    char *name = NULL;

    if (command[0] == '\0')
        return 0;
    name = fill_name_args(command, &args, &nb_args, env);
    if (access(name, X_OK) != 0) {
        my_printf("Command not found: %s\n", name);
        return 0;
    }
    if (fork() == 0) {
        execve(name, args, env);
        if (errno != 0)
            my_printf("%s\n", strerror(errno));
    }
    free_malloc(args, name);
    return 0;
}

int main(int argc, __attribute__((unused)) char **argv, char **env)
{
    char buffer[100];
    int fc = 0;

    if (error_handler(argc, argv) == 84)
        return 84;
    if (!isatty(0)) {
        istty(buffer, env);
        return 0;
    }
    while (1) {
        my_printf("$> ");
        fc = read(STDIN_FILENO, buffer, 100);
        buffer[fc - 1] = '\0';
        if (commands(buffer, env) == 1)
            return 0;
        else
            exec_process(buffer, env);
        wait(NULL);
    }
    return 0;
}
