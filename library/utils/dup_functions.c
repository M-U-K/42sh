/*
** EPITECH PROJECT, 2019
** Librairy
** File description:
** my_dups.c
*/

#include "utils.h"

#include <unistd.h>
#include <stdlib.h>

char *string_dup(char const *src)
{
    int len = 0;
    char *dest = NULL;

    if (src == NULL)
        return (NULL);
    for (; src[len] != '\0'; len++);
    dest = malloc(sizeof(char) * (len + 1));
    for (int ctr = 0; ctr < len; ctr++)
        dest[ctr] = src[ctr];
    dest[len] = '\0';
    return (dest);
}

char **table_dup(char * const *tab)
{
    int height = table_len(tab);
    char **new = malloc(sizeof(char *) * (height + 1));

    if (tab == NULL)
        return (free(new), NULL);
    for (int ctr = 0; ctr < height; ctr += 1)
        new[ctr] = string_dup(tab[ctr]);
    new[height] = NULL;
    return (new);
}