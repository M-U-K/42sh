/*
** EPITECH PROJECT, 2020
** unset_local.c
** File description:
** remove local variable
*/

#include "shell.h"

void remove_local(data_t *data, command_t *command)
{
    local_t *target = data->var;

    while (target) {
        if (compare(target->local, command->parsed[1])) {
            if (target->prev)
                target->prev->next = target->next;
            else
                data->var = target->next;
            if (target->next)
                target->next->prev = target->prev;
            if (!target->prev && !target->next)
                data->alias = NULL;
            free(target->value);
            free(target);
            return;
        }
        target = target->next;
    }
}

int unset_local(data_t *data, command_t *command)
{
    if (command->arg <= 1) {
        data->status = "1";
        printf("%s: Too few arguments.\n", command->parsed[0]);
    }
    for (int i = 1; command->parsed[i]; i++) {
        remove_local(data, command);
    }
    return (1);
}