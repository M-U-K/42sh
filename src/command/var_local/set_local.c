/*
** EPITECH PROJECT, 2020
** set_loal.c
** File description:
** define local variable
*/

#include "shell.h"

int local_exist(data_t *data, command_t *command)
{
    local_t *local = data->var;
    char **result = NULL;

    if (!is_alpha_num(str_to_tab(command->parsed[1], "=")[0], "_")) {
        return (1,
        printf("set: Variable name must contain alphanumeric characters.\n"));
    }
    while (local) {
        result = str_to_tab(command->parsed[1], "=");
        if (compare(local->local, result[0])) {
            free(local->value);
            for (int i = 1; command->parsed[i]; i++) {
                result = str_to_tab(command->parsed[i], "=");
                local->value = (result[1]) ? strdup(result[1]) : NULL;
            }
            return (1);
        }
        local =local->next;
    }
    return (0);
}

void define_local_value(local_t *new, char **result, local_t *last)
{
    new->local = strdup(result[0]);
    new->value = (result[1]) ? strdup(result[1]) : NULL;
    new->prev = last;
    new->next = NULL;
}

void create_new_local(data_t *data, command_t *command)
{
    local_t *last = data->var;
    local_t *new = NULL;
    char **result = NULL;

    if (local_exist(data, command)) {
        free(new);
        return;
    }
    while (last && last->next)
        last = last->next;
    for (int i = 1; command->parsed[i]; i++) {
        new = malloc(sizeof(local_t));
        result = str_to_tab(command->parsed[i], "=");
        define_local_value(new, result, last);
        if (!last)
            data->var = new;
        else
            last->next = new;
        last = new;
    }
}

void display_local_var(data_t *data)
{
    local_t *var = data->var;

    while (var) {
        printf("%s\t%s\n", var->local, var->value);
        var = var->next;
    }
}

int set_local(data_t *data, command_t *command)
{
    if (command->arg == 1)
        display_local_var(data);
    else
    if ((command->parsed[1][0] >= 'a' && command->parsed[1][0] <= 'z')\
|| (command->parsed[1][0] >= 'A' && command->parsed[1][0] <= 'Z')\
|| command->parsed[1][0] == '-') {
        data->status = "1";
        create_new_local(data, command);
    }
    else
        printf("set: Variable name must begin with a letter.\n");
    return (1);
}