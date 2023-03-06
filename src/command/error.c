/*
** EPITECH PROJECT, 2020
** error.c
** File description:
** display error
*/

#include "shell.h"

int check_bin(data_t *data, command_t *command, char *path)
{
    struct stat sb;

    (void)data;
    if (is_builtin(command))
        return (0);
    if (stat(path, &sb) == -1)
        return (-1);
    if (!S_ISREG(sb.st_mode)) {
        printf("%s: Exec format error. Wrong architecture.\n",
        command->parsed[0]);
        return (-1);
    }
    return (0);
}

int error_env(data_t *data, command_t *command)
{
    if (command->arg == 1)
        return (display_env(data));
    if (command->arg > 3) {
        my_put_str(command->parsed[0], 2);
        my_put_str(": Too many arguments.\n", 2);
        data->status = "1";
        return (1);
    }
    return (check_other_error(data, command));
}

void print_command_error(data_t *data, command_t *command, char *path)
{
    if (errno == EACCES) {
        my_put_str(command->parsed[0], 2);
        my_put_str(": Permission denied.\n", 2);
    }
    else if (check_bin(data, command, path) == -1)
        data->status = "1";
    else
        perror(command->parsed[0]);
    data->status = "1";
}

void print_term(data_t *data, int sig)
{
    int output = 2;

    switch (sig) {
    case 8:
        my_put_str("Floating exception\n", output);
        data->status = "136";
        break;
    case 11:
        my_put_str("Segmentation fault\n", output);
        data->status = "139";
        break;
    default:
        break;
    }
}

void check_crash(data_t *data, int w_status)
{
    int statue = WEXITSTATUS(w_status);

    if (WIFSIGNALED(w_status))
        print_term(data, WTERMSIG(w_status));
    if (statue != 0)
        data->status = get_integer_nbr(statue);
}