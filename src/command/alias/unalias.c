/*
** EPITECH PROJECT, 2020
** unalias.c
** File description:
** undefine alias
*/

#include "shell.h"

void change_pointer(data_t *data, alias_t *target)
{
    if (target->prev)
        target->prev->next = target->next;
    if (target->next)
        target->next->prev = target->prev;
    if (!target->prev && !target->next)
        data->alias = NULL;
}

void remove_alias(data_t *data, command_t *command)
{
    alias_t *target = data->alias;

    while (target) {
        if (compare(target->alias, command->parsed[1])) {
            change_pointer(data, target);
            free(target);
            return;
        }
        target = target->next;
    }
}

int unalias(data_t *data, command_t *command)
{
    if (command->arg <= 1) {
        data->status = "1";
        printf("%s: Too few arguments.\n", command->parsed[0]);
    }
    for (int i = 1; command->parsed[i]; i++) {
        remove_alias(data, command);
    }
    return (1);
}