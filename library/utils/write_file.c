/*
** EPITECH PROJECT, 2019
** Librairy
** File description:
** write_file.c
*/

#include <stdio.h>
#include <unistd.h>

#include "utils.h"

void write_file(char *filename, char *str)
{
    FILE *stream;
    int len = string_len(str, '\0');

    if (filename == NULL || filename[0] == '\0')
        return;
    stream = fopen(filename, "w");
    if (stream == NULL)
        return;
    fwrite(str, len, 1, stream);
    fclose(stream);
}