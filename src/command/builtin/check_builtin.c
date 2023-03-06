/*
** EPITECH PROJECT, 2020
** check_builtin.c
** File description:
** check if is builtin
*/

#include "shell.h"

int check_third_part(command_t *command)
{
    if (compare(command->parsed[0], "alias") ||\
compare(command->parsed[0], "unalias"))
        return (1);
    else if (compare(command->parsed[0], "set") ||\
compare(command->parsed[0], "unset"))
        return (1);
    return (0);
}

int check_second_part(command_t *command)
{
    if (compare(command->parsed[0], "unsetenv") ||\
compare(command->parsed[0], "cd"))
        return (1);
    return (check_third_part(command));
}

int is_builtin(command_t *command)
{
    if (compare(command->parsed[0], "env"))
        return (2);
    else if (compare(command->parsed[0], "setenv"))
        return (1);
    else
        return (check_second_part(command));
}