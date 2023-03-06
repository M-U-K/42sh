/*
** EPITECH PROJECT, 2019
** Librairy
** File description:
** my_realloc.c
*/

#include <stdbool.h>
#include <stdlib.h>

#include "utils.h"

char *my_realloc(char *str, int size, bool rewrite, bool want_free)
{
    char *dest = NULL;
    int ctr = 0;
    int len = 0;

    rewrite == false ? len = string_len(str, '\0') : 0;
    dest = malloc(sizeof(char) * (len + size + 1));
    if (dest == NULL)
        return (NULL);
    for (ctr = 0; str != NULL && str[ctr] != '\0'\
&& ctr < len + size; ctr += 1)
        dest[ctr] = str[ctr];
    while (ctr <= len + size) {
        dest[ctr] = '\0';
        ctr += 1;
    }
    want_free == true ? free(str) : 0;
    return (dest);
}