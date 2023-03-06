/*
** EPITECH PROJECT, 2019
** Librairy
** File description:
** string_len.c
*/

#include <unistd.h>

int string_len(char const *str, char end)
{
    int len = 0;

    if (str == NULL)
        return (0);
    while (str[len] != end && str[len] != '\0')
        len += 1;
    return (len);
}

int table_len(char * const *tab)
{
    int len = 0;

    if (tab == NULL)
        return (0);
    while (tab[len] != NULL)
        len += 1;
    return (len);
}