/*
** EPITECH PROJECT, 2020
** pipe.c
** File description:
** do pipe for shell
*/

#include "shell.h"

static void define_executed(command_t *command)
{
    command_t *cmd = command;

    while (cmd) {
        if (cmd && cmd->operator && cmd->operator[0] == '|')
            cmd->executed = 1;
        else {
            cmd->executed = 1;
            return;
        }
        cmd = cmd->next;
    }
}

static void child(data_t *data, command_t *cmd, int pfd[2])
{
    char *path = check_path(data, cmd->parsed[0]);

    if (cmd && cmd->operator && cmd->operator[0] == '|')
        dup2(pfd[1], 1);
    close(pfd[0]);
    if (is_builtin(cmd)) {
        execute_builtin(data, cmd);
        exit(0);
    } else
        execve(path, cmd->parsed, data->env);
    exit(84);
}

static int pipe_process(data_t *data, command_t *command, int *fd_in,
int pfd[2])
{
    int pid;
    int w_status = 0;

    data->status = "0";
    pipe(pfd);
    pid = fork();
    if (pid == 0) {
        dup2(*fd_in, 0);
        close(pfd[0]);
        child(data, command, pfd);
    } else {
        if (!(command && command->operator && command->operator[0] == '|'))
            waitpid(pid, &w_status, WUNTRACED | WCONTINUED);
        else
            waitpid(pid, &w_status, WUNTRACED | WEXITED);
        check_crash(data, w_status);
        close(pfd[1]);
        *fd_in = pfd[0];
    }
    return (0);
}

int is_null(data_t *data, command_t *current_cmd)
{
    char *path = NULL;

    path = check_path(data, current_cmd->parsed[0]);
    if (!path && !is_builtin(current_cmd)) {
        my_put_str(current_cmd->parsed[0], 2);
        my_put_str(": Command not found.\n", 2);
        data->status = "1";
        return (1);
    }
    return (0);
}

int execute_pipe(data_t *data, command_t *command)
{
    command_t *current_cmd = command;
    int pfd[2];
    int fd_in = 0;

    define_executed(command);
    while (current_cmd) {
        if (current_cmd->command[0] == '\0' ||
        (command && !command->next && command->operator &&
        command->operator[0] == '|')) {
            fprintf(stderr, "Invalid null command.\n");
            data->status = "1";
            return (-1);
        }
        if (is_null(data, current_cmd)) {
            current_cmd = current_cmd->next;
            continue;
        }
        pipe_process(data, current_cmd, &fd_in, pfd);
        current_cmd = current_cmd->next;
    }
    return (0);
}
