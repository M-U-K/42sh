/*
** EPITECH PROJECT, 2019
** my_strdup.c
** File description:
** allocate mem and copies the string
*/

#include "shell.h"

char *my_str_dup(char const *src)
{
    int srclen;
    char *str = NULL;
    int i;

    for (srclen = 0; src[srclen] != '\0'; srclen++);
    if (srclen == 0)
        return (str);
    if (srclen <= 0)
        return (0);
    str = malloc(sizeof(char) * (srclen + 1));
    for (i = 0; i < srclen; i++) {
        str[i] = src[i];
    }
    str[i] = '\0';
    return (str);
}
