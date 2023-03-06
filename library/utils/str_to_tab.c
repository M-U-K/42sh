/*
** EPITECH PROJECT, 2019
** Librairy
** File description:
** str_to_tab.c
*/

#include "utils.h"

#include <stdlib.h>

#include <stdio.h>

char *take_line(char const *str, char const *sep)
{
    int len = 0;
    char *line = NULL;

    if (str[0] == '"')
        for (str++; str[len] != '"' && str[len] != '\0'; len += 1);
    else
        while (is_in_string(str[len], sep) == false && str[len] != '\0')
            len += 1;
    line = malloc(sizeof(char) * (len + 1));
    for (int ctr = 0; ctr < len; ctr += 1)
        line[ctr] = str[ctr];
    line[len] = '\0';
    return (line);
}

int skip(char const *str, int ctr, char const *sep)
{
    if (str[ctr] == '"')
        for (ctr += 1; str[ctr] != '"'
        && str[ctr] != '\0'; ctr += 1);
    else
        for (ctr += 0; is_in_string(str[ctr], sep) == false
        && str[ctr] != '\0'; ctr += 1);
    return (ctr);
}

char **str_to_tab(char const *str, char const *sep)
{
    char **tab = NULL;
    char *tmp = NULL;

    for (int ctr = 0; str[ctr] != '\0';) {
        while (is_in_string(str[ctr], sep) == true\
&& str[ctr] != '"' && str[ctr] != '\0')
            ctr += 1;
        if (str[ctr] == '\0')
            break;
        tmp = take_line(&(str[ctr]), sep);
        tab = tab_append(tab, tmp);
        free(tmp);
        ctr = skip(str, ctr, sep);
        if (str[ctr] == '"')
            ctr += 1;
    }
    return (tab);
}