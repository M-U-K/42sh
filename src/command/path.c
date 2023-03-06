/*
** EPITECH PROJECT, 2020
** path.c
** File description:
** check if command exist in path
*/

#include "shell.h"

char *check_other_path(char *cmd)
{
    char *command = NULL;

    command = my_str_cat("/bin/", cmd);
    if (access(command, R_OK | X_OK) == 0)
        return (command);
    free(command);
    return (NULL);
}

char *check_path(data_t *data, char *cmd)
{
    char *path = get_env_var(data, "PATH");
    char **paths = NULL;
    char *command = NULL;

    if ((search_n_occurence(cmd, "/", 1) == 0 ||\
search_n_occurence(cmd, ".", 1) == 0))
        return ((access(cmd, R_OK | X_OK) == 0) ? cmd : NULL);
    paths = my_str_to_word_array(path, ':');
    for (int i = 0; path && paths[i]; i++) {
        command = my_str_cat(paths[i], "/");
        command = my_str_cat(command, cmd);
        if (access(command, R_OK | X_OK) == 0)
            return (command);
    }
    return (check_other_path(cmd));
}