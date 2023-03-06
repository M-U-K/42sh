/*
** EPITECH PROJECT, 2019
** Librairy
** File description:
** compare_string.c
*/

#include <unistd.h>

int cmp_string(char const *s1, char const *s2)
{
    if ((s1 == NULL && s2 == NULL) || (s1[0] == '\0' && s2[0] == '\0'))
        return (0);
    if ((s1 == NULL || s1[0] == '\0') || (s2 == NULL || s2[0] == '\0'))
        return (1);
    for (int ctr = 0; s1[ctr] != '\0' || s2[ctr] != '\0'; ctr++)
        if (s1[ctr] != s2[ctr])
            return (s1[ctr] - s2[ctr]);
    return (0);
}