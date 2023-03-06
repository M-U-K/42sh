/*
** EPITECH PROJECT, 2019
** Librairy
** File description:
** print_string.c
*/

#include <unistd.h>

void print_string(char const *str)
{
    int len = 0;

    while (str != NULL && str[len] != '\0')
        len += 1;
    write(1, str, len);
}