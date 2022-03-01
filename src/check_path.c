/*
** EPITECH PROJECT, 2022
** B-PSU-101-REN-1-1-minishell1-tom.daniel
** File description:
** get_path
*/

#include "my.h"
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <string.h>

void remove_begin(char *path)
{
    int l = 0;

    for (int i = 5; path[i] != '\0'; i++, l++)
        path[l] = path[i];
    path[l] = '\0';
}

void add_command(char *path, char *command)
{
    unsigned int i = 0;

    for (; path[i] != '\0'; i++);
    path[i] = '/';
    i++;
    for (unsigned int l = 0; command[l] != '\0'; i++, l++)
        path[i] = command[l];
    path[i] = '\0';
}

char **parse_buffer(char *buffer, char parse, int *nb_path)
{
    char **buffer2d = malloc(sizeof(char *) * (my_strlen(buffer) + 1));
    char *word = malloc(sizeof(char) * my_strlen(buffer) + 1);
    int l = 0;
    int i = 0;
    int j = 0;

    for (; i <= my_strlen(buffer); i++) {
        if (buffer[i] == parse || buffer[i] == '\0') {
            buffer2d[j] = malloc(sizeof(char) * (my_strlen(buffer) * 2));
            my_strcpy(buffer2d[j], word);
            j++;
            l = 0;
            i++;
        }
        word[l] = buffer[i];
        l++;
        word[l] = '\0';
    }
    *nb_path = j;
    return buffer2d;
}

char *check_path(char *str, char *command)
{
    char path[my_strlen(str)];
    char **buffer2d = NULL;
    int nb_path = 0;
    int found = 0;

    my_strcpy(path, str);
    buffer2d = parse_buffer(path, ':', &nb_path);
    int i = 0;
    while (i < nb_path) {
        add_command(buffer2d[i], command);
        if (access(buffer2d[i], X_OK) == 0) {
            found = 1;
            break;
        }
        i++;
    }
    if (found == 1)
        return buffer2d[i];
    return NULL;
}

char *get_path(char **env, char *command)
{
    int i = 0;
    char *path = NULL;

    while (env[i] != NULL) {
        if (my_strncmp("PATH=", env[i], 5) == true)
            break;
        i++;
    }
    path = malloc(sizeof(char) * (my_strlen(env[i]) + my_strlen(command) + 1));
    my_strcpy(path, env[i]);
    remove_begin(path);
    if (check_path(path, command) == NULL)
        return NULL;
    my_strcpy(path, check_path(path, command));
    return path;
}
