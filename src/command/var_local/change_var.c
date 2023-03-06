/*
** EPITECH PROJECT, 2020
** change_var.c
** File description:
** change local var in command
*/

#include "shell.h"

int change_var(data_t *data, command_t *command)
{
    int changed = 0;
    local_t *local = data->var;

    while (local) {
        for (int i = 0; command->parsed[i]; i++) {
            if (compare(&command->parsed[i][1], local->local)) {
                free(command->parsed[i]);
                command->parsed[i] = string_dup(local->value);
                changed = 1;
                break;
            }
        }
        local = local->next;
    }
    if (changed) {
        command->command = tab_to_str(command->parsed);
        command->parsed = str_to_tab(command->command, " \n");
    }
    return (0);
}