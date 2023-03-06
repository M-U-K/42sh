/*
** EPITECH PROJECT, 2019
** Librairy
** File description:
** str_clear.c
*/

#include <stdbool.h>
#include <stdlib.h>

#include "utils.h"

char *str_clear(char *str, char const *del, bool want_free)
{
    char *dest = NULL;
    int len = 0;
    int dest_ctr = 0;

    for (int ctr = 0; str != NULL && str[ctr] != '\0'; ctr += 1)
        if (is_in_string(str[ctr], del) == false)
            len += 1;
    dest = malloc(sizeof(char) * (len + 1));
    if (dest == NULL)
        return (NULL);
    for (int ctr = 0; str[ctr] != '\0'; ctr += 1)
        if (is_in_string(str[ctr], del) == false) {
            dest[dest_ctr] = str[ctr];
            dest_ctr += 1;
        }
    dest[len] = '\0';
    want_free == true ? free(str) : 0;
    return (dest);
}