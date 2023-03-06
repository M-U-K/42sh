/*
** EPITECH PROJECT, 2019
** Librairy
** File description:
** capitalize_string.c
*/

#include <unistd.h>

#include "utils.h"

char *capitalize_string(char *str)
{
    int ctr = 0;

    if (str == NULL)
        return (NULL);
    str = lowcase_string(str);
    for (; str[ctr] != '\0'; ctr++) {
        if ('a' <= str[ctr] && str[ctr] <= 'z' && (ctr == 0 ||\
(('a' > str[ctr - 1] || str[ctr - 1] > 'z') &&\
('A' > str[ctr - 1] || str[ctr - 1] > 'Z') &&\
('0' > str[ctr - 1] || str[ctr - 1] > '9'))))
            str[ctr] -= 32;
    }
    str[ctr] = '\0';
    return (str);
}