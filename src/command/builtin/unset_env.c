/*
** EPITECH PROJECT, 2020
** unset_env.c
** File description:
** remove env var
*/

#include "shell.h"

void remove_var(data_t *data, command_t *command, char **new_env)
{
    int index = 0;

    new_env[data->nbr_env_var - 1] = NULL;
    for (int i = 0; data->env[i]; i++) {
        if (start_with(data->env[i], command->parsed[1])) {
            data->nbr_env_var -= 1;
            continue;
        }
        new_env[index] = my_str_dup(data->env[i]);
        index += 1;
    }
    for (int i = 0; data->env[i]; i++)
        free(data->env[i]);
    free(data->env);
    data->env = copy_env(data, new_env);
    for (int i = 0; new_env[i]; i++)
        free(new_env[i]);
    free(new_env);
}

int error_unsetenv(data_t *data, command_t *command)
{
    if (command->arg < 2) {
        my_put_str(command->parsed[0], 2);
        my_put_str(": Too few arguments.\n", 2);
        data->status = "1";
        return (1);
    }
    return (0);
}

int unset_env(data_t *data, command_t *command)
{
    char **new_env = malloc(sizeof(char *) * (data->nbr_env_var));
    char *var = NULL;

    if (error_unsetenv(data, command))
        return (1);
    var = get_env_var(data, command->parsed[1]);
    if (!var)
        return (1);
    remove_var(data, command, new_env);
    return (1);
}