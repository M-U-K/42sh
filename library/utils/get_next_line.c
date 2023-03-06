/*
** EPITECH PROJECT, 2019
** getnextline
** File description:
** get_next_line.c
*/

#include <stdio.h>

#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>

#include "utils.h"

/*
char *my_realloc(char *str, int size, bool rewrite, bool want_free)
{
    char *dest = NULL;
    int ctr = 0;
    int len = 0;

    while (rewrite == false && str != NULL && str[len] != '\0')
        len += 1;
    dest = malloc(sizeof(char) * (len + size + 1));
    if (dest == NULL)
        return (NULL);
    for (ctr = 0; str != NULL && str[ctr] != '\0'
    && ctr < len + size; ctr += 1)
        dest[ctr] = str[ctr];
    while (ctr <= len + size) {
        dest[ctr] = '\0';
        ctr += 1;
    }
    if (want_free == true)
        free(str);
    return (dest);
}
*/

/*
char *my_strcat(char *src, char *add_str)
{
    char *dest = NULL;
    int dest_ctr = 0;
    int len = 0;

    if (src == NULL && add_str == NULL)
        return (NULL);
    while (add_str != NULL && add_str[len] != '\0')
        len += 1;
    for (int ctr = 0; src != NULL && src[ctr] != '\0'; ctr += 1)
        len += 1;
    if ((dest = malloc(sizeof(char) * (len + 1))) == NULL)
        return (NULL);
    for (int ctr = 0; src != NULL
    && src[ctr] != '\0'; ctr += 1, dest_ctr += 1)
        dest[dest_ctr] = src[ctr];
    for (int ctr = 0; add_str != NULL
    && add_str[ctr] != '\0'; ctr += 1, dest_ctr += 1)
        dest[dest_ctr] = add_str[ctr];
    dest[dest_ctr] = '\0';
    return (dest);
}
*/

int contain_line_return(char *str)
{
    int ctr = 0;

    if (str == NULL)
        return (-1);
    while (str[ctr] != '\0') {
        if (str[ctr] == '\n')
            return (ctr);
        ctr += 1;
    }
    return (-1);
}

char *get_next_line(int fd)
{
    static char *tmp = NULL;
    static bool end = false;
    char *buffer = my_realloc(tmp, READ_SIZE, true, false);
    char *result = NULL;
    int check = READ_SIZE;
    int i = -1;

    while (check != -1 && end == false && buffer != NULL) {
        i = contain_line_return(buffer);
        if (i != -1 || check == 0) {
            tmp = my_realloc(&(buffer[i + 1]), 0, false, false);
            buffer = my_realloc(buffer, i, true, true);
        }
        result = concat_fstring("%s%s", result, buffer);
        check == 0 ? end = true : false;
        if (i != -1 || check == 0)
            return (result[0] == '\0' ? NULL : result);
        buffer = my_realloc(NULL, READ_SIZE, true, true);
        check = read(fd, buffer, READ_SIZE);
    }
    return (NULL);
}