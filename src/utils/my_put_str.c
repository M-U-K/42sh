/*
** EPITECH PROJECT, 2019
** my_putstr
** File description:
** Display one by one char of a string parameter
*/

#include "shell.h"

int my_put_str(char *str, int channel)
{
    int length = 0;

    if (!str)
        return (-1);
    for (length = 0; str[length] != '\0'; length++);
    write(channel, str, length);
    return (0);
}
