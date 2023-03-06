/*
** EPITECH PROJECT, 2020
** alias.c
** File description:
** define or display alias
*/

#include "shell.h"

char *get_result(command_t *command)
{
    char *result = NULL;

    for (int i = 2; command->parsed[i]; i++)
        result = concat_fstring("%s %s", result, command->parsed[i]);
}

int alias_exist(data_t *data, command_t *command)
{
    alias_t *alias = data->alias;

    while (alias) {
        if (compare(alias->alias, command->parsed[0])) {
            free(alias->command);
            alias->command = get_result(command);
            return (1);
        }
        alias =alias->next;
    }
    return (0);
}

void create_new_alias(data_t *data, command_t *command)
{
    alias_t *last = data->alias;
    alias_t *new = malloc(sizeof(alias_t));
    char *result = NULL;

    if (command->arg < 3 || alias_exist(data, command)) {
        free(new);
        return;
    }
    while (last && last->next)
        last = last->next;
    new->alias = strdup(command->parsed[1]);
    for (int i = 2; command->parsed[i]; i++)
        result = concat_fstring("%s %s", result, command->parsed[i]);
    new->command = result;
    new->prev = last;
    new->next = NULL;
    if (!last)
        data->alias = new;
    else
        last->next = new;
}

void display_alias(data_t *data)
{
    alias_t *alias = data->alias;

    while (alias) {
        printf("%s\t%s\n", alias->alias, alias->command);
        alias = alias->next;
    }
}

int alias(data_t *data, command_t *command)
{
    if (command->arg == 1)
        display_alias(data);
    else
        create_new_alias(data, command);
    return (1);
}