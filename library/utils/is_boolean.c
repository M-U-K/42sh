/*
** EPITECH PROJECT, 2019
** Tetris_2019
** File description:
** is_boolean.c
*/

#include "utils.h"

int is_boolean(char const *value)
{
    if (cmp_string("true", value) == 0)
        return (1);
    else if (cmp_string("false", value) == 0)
        return (0);
    return (-1);
}