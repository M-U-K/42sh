/*
** EPITECH PROJECT, 2019
** Librairy
** File description:
** lowcase_string.c
*/

#include <unistd.h>

char *lowcase_string(char *str)
{
    if (str == NULL)
        return (NULL);
    for (int ctr = 0; str[ctr] != '\0'; ctr++)
        if ('A' <= str[ctr] && str[ctr] <= 'Z')
            str[ctr] += 32;
    return (str);
}