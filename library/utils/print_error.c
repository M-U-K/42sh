/*
** EPITECH PROJECT, 2019
** Librairy
** File description:
** print_error.c
*/

#include <unistd.h>

void print_error(char const *error)
{
    int len = 0;

    while (error != NULL && error[len] != '\0')
        len += 1;
    write(2, error, len);
}