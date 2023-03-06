/*
** EPITECH PROJECT, 2019
** Librairy
** File description:
** is_alpha_num.c
*/

#include <stdbool.h>
#include <unistd.h>

#include "utils.h"

bool is_num(char *str, char *except)
{
    for (int ctr = 0; str != NULL && str[ctr] != '\0'; ctr += 1)
        if ((str[ctr] < '0' || str[ctr] > '9') &&\
is_in_string(str[ctr], except) == false)
            return (false);
    return (true);
}

bool is_alpha(char *str, char *except)
{
    for (int ctr = 0; str != NULL && str[ctr] != '\0'; ctr += 1)
        if ((str[ctr] < 'a' || str[ctr] > 'z') &&\
(str[ctr] < 'A' || str[ctr] > 'Z') &&\
is_in_string(str[ctr], except) == false)
            return (false);
    return (true);
}

bool is_alpha_low(char *str, char *except)
{
    for (int ctr = 0; str != NULL && str[ctr] != '\0'; ctr += 1)
        if ((str[ctr] < 'a' || str[ctr] > 'z') &&\
is_in_string(str[ctr], except) == false)
            return (false);
    return (true);
}

bool is_alpha_upp(char *str, char *except)
{
    for (int ctr = 0; str != NULL && str[ctr] != '\0'; ctr += 1)
        if ((str[ctr] < 'A' || str[ctr] > 'Z') &&\
is_in_string(str[ctr], except) == false)
            return (false);
    return (true);
}

bool is_alpha_num(char *str, char *except)
{
    if (is_alpha(str, except) == false && is_num(str, except) == false)
        return (false);
    return (true);
}