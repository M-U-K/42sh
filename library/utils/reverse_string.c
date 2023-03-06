/*
** EPITECH PROJECT, 2019
** Librairy
** File description:
** reverse_string.c
*/

#include <unistd.h>
#include "utils.h"

char *reverse_string(char *str)
{
    int size = string_len(str, '\0');
    char tmp[size];
    int j = 0;

    if (str == NULL)
        return (NULL);
    for (int i = 0; str[i] != '\0'; i += 1)
        tmp[i] = str[i];
    j = size - 1;
    for (int i = 0; str[i] != '\0'; i += 1) {
        str[i] = tmp[j];
        j -= 1;
    }
    return (str);
}