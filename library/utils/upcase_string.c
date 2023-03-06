/*
** EPITECH PROJECT, 2019
** Librairy
** File description:
** upcase_string.c
*/

#include <unistd.h>

char *upcase_string(char *str)
{
    if (str == NULL)
        return (NULL);
    for (int ctr = 0; str[ctr] != '\0'; ctr++)
        if ('a' <= str[ctr] && str[ctr] <= 'z')
            str[ctr] -= 32;
    return (str);
}