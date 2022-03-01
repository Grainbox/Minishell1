/*
** EPITECH PROJECT, 2022
** Project_Template
** File description:
** my_h_structure
*/

#ifndef MY_H_STRUCTURE_H_
    #define MY_H_STRUCTURE_H_

    struct my_str_to_word_array_struct {
        char const *str;
        int i;
        int *word;
        char **str_rtn;
        int word_ok;
        int letter;
        int l;
    };
    typedef struct my_str_to_word_array_struct to_word;


#endif
