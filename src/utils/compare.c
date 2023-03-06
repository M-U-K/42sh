/*
** EPITECH PROJECT, 2019
** compare.c
** File description:
** want to compare an str?
*/

#include "shell.h"

int compare(char const *str1, char const *str2)
{
    int len_a = my_str_len(str1);
    int len_b = my_str_len(str2);

    if (!str1 || !str2 || len_a != len_b)
        return (0);
    for (int i = 0; str1[i] != '\0'; i++)
        if (str1[i] != str2[i])
            return (0);
    return (1);
}