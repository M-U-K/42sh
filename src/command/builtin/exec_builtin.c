/*
** EPITECH PROJECT, 2020
** exec_builtin.c
** File description:
** execute our builtin
*/

#include "shell.h"

void exec_fourth_part(data_t *data, command_t *command)
{
    if (compare(command->parsed[0], "set"))
        set_local(data, command);
    if (compare(command->parsed[0], "unset"))
        unset_local(data, command);
}

void exec_third_part(data_t *data, command_t *command)
{
    if (compare(command->parsed[0], "alias"))
        alias(data, command);
    else if (compare(command->parsed[0], "unalias"))
        unalias(data, command);
    else
        exec_fourth_part(data, command);
}

void exec_second_part(data_t *data, command_t *command)
{
    if (compare(command->parsed[0], "unsetenv"))
        unset_env(data, command);
    else if (compare(command->parsed[0], "cd"))
        change_dir(data, command);
    else
        exec_third_part(data, command);
}

void execute_builtin(data_t *data, command_t *command)
{
    if (compare(command->parsed[0], "env"))
        display_env(data);
    else if (compare(command->parsed[0], "setenv"))
        set_env(data, command);
    else
        exec_second_part(data, command);
}