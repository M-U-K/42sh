/*
** EPITECH PROJECT, 2020
** promt.c
** File description:
** display prompt
*/

#include "shell.h"

char *get_complete_path(int *size)
{
    char *path = NULL;

    while (!path) {
        *size += 1;
        path = getcwd(path, *size);
    }
    return (path);
}

char *get_current_path(int cut)
{
    int size = 0;
    char *path = get_complete_path(&size);
    char *result = NULL;
    int length = 0;
    int index = 0;

    if (!cut)
        return (path);
    for (int i = size - 1; path[i] != '/'; i--)
        length += 1;
    result = malloc(sizeof(char *) * (length + 1));
    for (int i = size - length; path[i] != '\0'; i++) {
        result[index] = path[i];
        index += 1;
    }
    result[index] = '\0';
    free(path);
    return (result);
}

void print_prompt(void)
{
    char *path = get_current_path(1);

    if (isatty(0)) {
        write(1, "[", 1);
        my_put_str(path, 1);
        my_put_str("] §> ", 1);
    }
    free(path);
}