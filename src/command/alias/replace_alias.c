/*
** EPITECH PROJECT, 2020
** replace_alias.c
** File description:
** replace alias in command
*/

#include "shell.h"

void change_alias(data_t *data, command_t *command)
{
    int changed = 0;
    alias_t *alias = data->alias;

    while (alias) {
        if (compare(command->parsed[0], alias->alias)) {
            free(command->parsed[0]);
            command->parsed[0] = string_dup(alias->command);
            changed = 1;
            break;
        }
        alias = alias->next;
    }
    if (changed) {
        command->command = tab_to_str(command->parsed);
        command->parsed = str_to_tab(command->command, " \n");
    }
}