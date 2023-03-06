/*
** EPITECH PROJECT, 2019
** Librairy
** File description:
** sort_word.c
*/

#include <unistd.h>

#include "utils.h"

char **sort_word(char **word_list)
{
    int nb_word = table_len(word_list);
    int count_loop = 0;
    char *tmp = NULL;

    for (int ctr = 0; word_list != NULL && count_loop <= nb_word; ctr += 1) {
        if (word_list[ctr] == NULL) {
            count_loop += 1;
            ctr = 0;
        }
        if (word_list[ctr] != NULL
        && cmp_string_alpha(word_list[ctr], word_list[ctr + 1]) < 0) {
            tmp = word_list[ctr];
            word_list[ctr] = word_list[ctr + 1];
            word_list[ctr + 1] = tmp;
        }
    }
    return (word_list);
}