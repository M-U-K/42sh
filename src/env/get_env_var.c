/*
** EPITECH PROJECT, 2020
** get_env_var.c
** File description:
** get env variable
*/

#include "shell.h"

int check_env_var(char const *env, char const *str)
{
    for (int i = 0; env[i] != '\0' && env[i] != '=' && str[i] != '\0'; i++) {
        if (env[i] != str[i])
            return (1);
    }
    return (0);
}

char *get_env_var(data_t *data, char *var)
{
    if (!var || var[0] == '\0')
        return (NULL);
    for (int i = 0; data->env[i]; i++) {
        if (check_env_var(data->env[i], var) == 0)
            return (data->env[i]);
    }
    return (NULL);
}
