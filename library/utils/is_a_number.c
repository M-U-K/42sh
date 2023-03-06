/*
** EPITECH PROJECT, 2019
** Librairy
** File description:
** is_a_number.c
*/

#include <stdbool.h>
#include <unistd.h>

bool is_a_number(char const *str)
{
    for (int ctr = 0; str != NULL && str[ctr] != '\0'; ctr += 1)
        if ('0' > str[ctr] || str[ctr] > '9')
            return (false);
    return (true);
}