/*
** EPITECH PROJECT, 2019
** Librairy
** File description:
** table_suppress.c
*/

#include <stdlib.h>

#include "utils.h"

char **tab_suppress(char **tab, int n)
{
    int height = table_len(tab) - 1;
    char **result = malloc(sizeof(char *) * (height + 1));
    int result_ctr = 0;

    for (int ctr = 0; tab[ctr] != NULL; ctr += 1) {
        if (ctr == n)
            continue;
        result[result_ctr] = string_dup(tab[ctr]);
        result_ctr += 1;
    }
    result[height] = NULL;
    free_tab(tab);
    return (result);
}