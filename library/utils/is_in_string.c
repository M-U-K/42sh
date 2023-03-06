/*
** EPITECH PROJECT, 2019
** Librairy
** File description:
** is_in_string.c
*/

#include <unistd.h>
#include <stdbool.h>

bool is_in_string(char c, char const *str)
{
    for (int ctr = 0; str != NULL && str[ctr] != '\0'; ctr += 1)
        if (str[ctr] == c)
            return (true);
    return (false);
}