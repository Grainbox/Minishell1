/*
** EPITECH PROJECT, 2022
** Project_Template
** File description:
** my_str_to_word_array2
*/

#include "my_h_structure.h"
#include <stdlib.h>

void malloc_str_rtn(char **str_rtn, int word_ok, int letter, int l)
{
    if (word_ok != 0)
        str_rtn[l] = malloc(sizeof(char) * letter + 1);
}

int count_word(to_word vars)
{
    if (vars.str[vars.i + 1] == '\0') {
        vars.word++;
        malloc_str_rtn(vars.str_rtn, vars.word_ok, vars.letter, vars.l);
    }
    return *vars.word;
}

int do_add_l(int *l, int word_ok)
{
    if (word_ok != 0)
        ++(*l);
}
