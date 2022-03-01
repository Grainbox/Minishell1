/*
** EPITECH PROJECT, 2022
** B-PSU-101-REN-1-1-minishell1-tom.daniel
** File description:
** minishell
*/

#ifndef MINISHELL_H_
    #define MINISHELL_H_

    char *get_path(char **env, char *command);

    int istty(char *buffer, char **env);

    int exec_process(char *command, char **env);

    int error_handler(int argc, char **argv);

    int commands(char *command, char **env);

    void free_malloc(char **args, char *name);

#endif
