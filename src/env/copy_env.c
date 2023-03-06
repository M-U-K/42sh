/*
** EPITECH PROJECT, 2020
** copy_env.c
** File description:
** copy the env
*/

#include "shell.h"

char **copy_env(data_t *data, char **env)
{
    char **result = NULL;
    int nbr_line = 0;

    data->nbr_env_var = 0;
    for (nbr_line = 0; env[nbr_line]; nbr_line++);
    result = malloc(sizeof(char *) * (nbr_line + 1));
    result[nbr_line] = NULL;
    for (int i = 0; env[i]; i++) {
        result[i] = my_str_dup(env[i]);
        data->nbr_env_var += 1;
    }
    return (result);
}