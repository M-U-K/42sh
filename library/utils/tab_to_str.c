/*
** EPITECH PROJECT, 2019
** Librairy
** File description:
** tab_to_str.c
*/

#include <stdlib.h>

#include "utils.h"

char *tab_to_str(char * const *tab)
{
    char *tmp = NULL;
    char *dest = string_dup(tab[0]);

    if (dest == NULL)
        return (NULL);
    for (int ctr = 1; tab != NULL && tab[ctr] != NULL; ctr += 1) {
        tmp = concat_fstring("%s:%s", dest, tab[ctr]);
        free(dest);
        dest = string_dup(tmp);
        free(tmp);
    }
    return (dest);
}