/*
** EPITECH PROJECT, 2019
** Librairy
** File description:
** read_file.c
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>

#include "utils.h"

char *read_stat_file(char const *filename)
{
    char *content = NULL;
    struct stat st;
    int fd = 0;

    if (filename == NULL || filename[0] == '\0')
        return (print_error("read_stat_file(): Wrong filename\n"), NULL);
    if (stat(filename, &st) == -1)
        return (print_error("read_stat_file(): Can't open\n"), NULL);
    fd = open(filename, O_RDONLY);
    if (fd == -1)
        return (print_error("read_stat_file(): Can't open\n"), NULL);
    content = malloc(sizeof(char) * (st.st_size + 1));
    if (content == NULL)
        return (print_error("read_stat_file(): Can't malloc\n"), NULL);
    if (read(fd, content, st.st_size) == -1)
        return (print_error("read_stat_file(): Can't read\n"), NULL);
    content[st.st_size] = '\0';
    close(fd);
    return (content);
}

char *read_read_file(char const *filename)
{
    char *content = NULL;
    char *tmp = malloc(sizeof(char) * (READ_SIZE + 1));
    int fd = open(filename, O_RDONLY);
    int check = 0;

    tmp[READ_SIZE] = '\0';
    if (fd == -1)
        return (NULL);
    while ((check = read(fd, tmp, READ_SIZE)) != 0) {
        tmp[check] = '\0';
        content = concat_fstring("%s%s", content, tmp);
    }
    close(fd);
    return (content);
}

char *read_getline_file(char const *filename)
{
    char *content = NULL;
    char *tmp = NULL;

    while (tmp != NULL) {

    }
    return (content);
}