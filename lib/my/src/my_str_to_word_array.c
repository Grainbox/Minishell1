/*
** EPITECH PROJECT, 2021
** my_str_to_word_array
** File description:
** store word into array
*/

#include <stdlib.h>
#include "my_h_structure.h"

int my_strlen(char const *str);

int count_word(to_word vars);

void malloc_str_rtn(char **str_rtn, int word_ok, int letter, int l);

int do_add_l(int *l, int word_ok);


int check_alpha(char c)
{
    if (c >= '0' && c <= '9')
        return 1;
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
        return 1;
    return 0;
}

char **store_words(char const *str, char **str_rtn)
{
    int i = 0;
    int nb_wrd = 0;
    int chr_wrd = 0;

    while (str[i] != '\0') {
        if (check_alpha(str[i]) == 1) {
            str_rtn[nb_wrd][chr_wrd] = str[i];
            chr_wrd++;
        } else if (chr_wrd > 0) {
            str_rtn[nb_wrd][chr_wrd] = '\0';
            nb_wrd++;
            chr_wrd = 0;
        }
        i++;
    }
    return (str_rtn);
}

int count_words(char const *str, int word_ok, char **str_rtn)
{
    int i = 0;
    int l = 0;
    int letter = 0;
    int word = 0;
    to_word vars = { str, i, &word, str_rtn, word_ok, letter, l };

    for (i = 0; str[i] != '\0'; i++) {
        if (check_alpha(str[i]) == 1) {
            letter++;
            word = count_word(vars);
        } else if (letter > 0) {
            malloc_str_rtn(str_rtn, word_ok, letter, l);
            do_add_l(&l, word_ok);
            word++;
            letter = 0;
        }
    }
    return (word);
}

char **my_str_to_word_array(char const *str)
{
    int word = 0;
    char **str_rtn;

    str_rtn = malloc(sizeof(char *) * (count_words(str, 0, str_rtn) + 1));
    word = count_words(str, word, str_rtn);
    count_words(str, word, str_rtn);
    str_rtn = store_words(str, str_rtn);
    return (str_rtn);
}
