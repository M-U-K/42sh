/*
** EPITECH PROJECT, 2019
** Librairy
** File description:
** table_append.c
*/

#include <stdlib.h>

#include "utils.h"

char **tab_append(char **tab, char *str)
{
    int height = table_len(tab);
    char **new = malloc(sizeof(char *) * (height + 2));

    for (int ctr = 0; ctr < height; ctr += 1)
        new[ctr] = string_dup(tab[ctr]);
    new[height] = string_dup(str);
    new[height + 1] = NULL;
    free_tab(tab);
    return (new);
}