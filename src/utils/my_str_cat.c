/*
** EPITECH PROJECT, 2020
** my_str_cat.c
** File description:
** str_cat
*/

#include "shell.h"

char *my_str_cat(char const *dest, char const *src)
{
    int len_a = 0;
    int len_b = 0;
    char *result = NULL;
    int index = 0;

    for (len_a = 0; dest[len_a] != '\0'; len_a++);
    for (len_b = 0; src[len_b] != '\0'; len_b++);
    result = malloc(sizeof(char) * (len_a + len_b + 1));
    for (int i = 0; dest[i] != '\0'; i++) {
        result[index] = dest[i];
        index += 1;
    }
    for (int i = 0; src[i] != '\0'; i++) {
        result[index] = src[i];
        index += 1;
    }
    result[len_a + len_b] = '\0';
    return (result);
}