/*
** EPITECH PROJECT, 2019
** Librairy
** File description:
** compare_string_alpha.c
*/

#include <unistd.h>
#include <stdbool.h>

bool test_alpha(char a, char b)
{
    if (('a' <= a && a <= 'z' && 'A' <= b && b <= 'Z' && b - a < 0)\
|| ('A' <= a && a <= 'Z' && 'a' <= b && b <= 'z' && a - b < 0))
        return (true);
    return (false);
}

int cmp_string_alpha(char const *s1, char const *s2)
{
    if ((s1 == NULL && s2 == NULL) || (s1[0] == '\0' && s2[0] == '\0'))
        return (0);
    if ((s1 == NULL || s1[0] == '\0') || (s2 == NULL || s2[0] == '\0'))
        return (1);
    for (int ctr = 0; s1[ctr] != '\0' && s2[ctr] != '\0'; ctr += 1)
        if (s1[ctr] != s2[ctr] && test_alpha(s1[ctr], s2[ctr]) == false)
	    return (s2[ctr] - s1[ctr]);
    return (0);
}