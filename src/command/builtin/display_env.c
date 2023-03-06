/*
** EPITECH PROJECT, 2020
** display_env.c
** File description:
** display shell env
*/

#include "shell.h"

int display_env(data_t *data)
{
    for (int i = 0; data->env[i]; i++) {
        my_put_str(data->env[i], data->redirection);
        my_put_str("\n", data->redirection);
    }
    return (1);
}

static void create_new_variable(data_t *data, char **parsed_command)
{
    char **new_env = malloc(sizeof(char *) * (data->nbr_env_var + 2));
    char *new_var = NULL;

    new_env[data->nbr_env_var + 1] = NULL;
    for (int i = 0; data->env[i]; i++)
        new_env[i] = my_str_dup(data->env[i]);
    new_var = my_str_cat(parsed_command[1], "=");
    new_env[data->nbr_env_var] = new_var;
    if (parsed_command[2])
        new_env[data->nbr_env_var] = my_str_cat(new_var, parsed_command[2]);
    data->nbr_env_var += 1;
    for (int i = 0; data->env[i]; i++)
        free(data->env[i]);
    free(data->env);
    data->env = copy_env(data, new_env);
    for (int i = 0; new_env[i]; i++)
        free(new_env[i]);
    free(new_env);
}

void define_var(data_t *data, char **parsed_command)
{
    for (int i = 0; data->env[i]; i++) {
        if (start_with(data->env[i], parsed_command[1])) {
            free(data->env[i]);
            data->env[i] = my_str_cat(parsed_command[1], "=");
            if (parsed_command[2])
                data->env[i] = my_str_cat(data->env[i], parsed_command[2]);
            return;
        }
    }
}

int check_other_error(data_t *data, command_t *command)
{
    if (!is_alphanum(command->parsed[1])) {
        my_put_str(command->parsed[0], 2);
        my_put_str(": Variable name must contain alphanumeric "
        "characters.\n", 2);
        data->status = "1";
        return (1);
    }
    if ((command->parsed[1][0] < 'a' || command->parsed[1][0] > 'z') &&
    (command->parsed[1][0] < 'A' || command->parsed[1][0] > 'Z')
    && command->parsed[1][0] != '_') {
        my_put_str(command->parsed[0], 2);
        my_put_str(": Variable name must begin with a letter.\n", 2);
        data->status = "1";
        return (1);
    }
    return (0);
}

int set_env(data_t *data, command_t *command)
{
    char **parsed_command = my_str_to_word_array(command->command, ' ');
    char *env_var = get_env_var(data, parsed_command[1]);

    if (error_env(data, command))
        return (1);
    if (!env_var)
        create_new_variable(data, parsed_command);
    else
        define_var(data, parsed_command);
    return (1);
}