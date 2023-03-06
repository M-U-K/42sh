/*
** EPITECH PROJECT, 2020
** change_dir.c
** File description:
** cd command
*/

#include "shell.h"

static int error(data_t *data, command_t *command, char *path)
{
    struct stat sb;

    if (command->arg > 2) {
        my_put_str(command->parsed[0], 2);
        my_put_str(": Too many arguments.\n", 2);
        data->status = "1";
        return (1);
    }
    if (stat(path, &sb) == -1) {
        my_put_str(path, 2);
        my_put_str(": No such file or directory.\n", 2);
        data->status = "1";
        return (1);
    }
    if ((sb.st_mode & S_IFMT) != S_IFDIR) {
        my_put_str(path, 2);
        my_put_str(": Not a directory.\n", 2);
        data->status = "1";
    }
    return (0);
}

static void home(data_t *data, command_t *command)
{
    char *home = get_env_var(data, "HOME");
    char **home_path = my_str_to_word_array(home, '=');
    char *path[3];

    if (!home_path) {
        my_put_str(command->parsed[0], 2);
        my_put_str(": No home directory.\n", 2);
        data->status = "1";
        return;
    }
    if (error(data, command, home_path[1]))
        return;
    data->last_dir = get_current_path(0);
    chdir(home_path[1]);
    path[0] = NULL;
    path[1] = "PWD";
    path[2] = get_current_path(0);
    define_var(data, path);
}

static void last_dir(data_t *data, command_t *command)
{
    char *last_path = data->last_dir;
    char *path[3];

    if (error(data, command, last_path))
        return;
    data->last_dir = get_current_path(0);
    chdir(last_path);
    path[0] = NULL;
    path[1] = "PWD";
    path[2] = get_current_path(0);
    define_var(data, path);
}

int change_dir(data_t *data, command_t *command)
{
    char *path[3];

    if (compare(command->parsed[1], "~") || !command->parsed[1])
        home(data, command);
    else if (compare(command->parsed[1], "-")) {
        last_dir(data, command);
    } else {
        if (error(data, command, command->parsed[1]))
            return (1);
        data->last_dir = get_current_path(0);
        chdir(command->parsed[1]);
        path[0] = NULL;
        path[1] = "PWD";
        path[2] = get_current_path(0);
        define_var(data, path);
    }
    return (1);
}