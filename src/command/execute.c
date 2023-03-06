/*
** EPITECH PROJECT, 2020
** execute.c
** File description:
** execute one command
*/

#include "shell.h"

void execution(data_t *data, command_t *command, char *path)
{
    if (is_builtin(command)) {
        execute_builtin(data, command);
        if (is_builtin(command) == 2)
            exit(0);
    } else {
        execve(path, command->parsed, data->env);
        print_command_error(data, command, path);
        exit(84);
    }
}

void process_exec_command(data_t *data, command_t *command, char *path)
{
    int pid = 0;
    int w_status = 0;

    data->status = "0";
    if (is_builtin(command) == 2 || !is_builtin(command))
        pid = fork();
    if (pid == 0) {
        prepare_redirection(data, command);
        execution(data, command, path);
    }
    if (is_builtin(command) == 2 || !is_builtin(command))
        waitpid(pid, &w_status, WUNTRACED | WCONTINUED);
    close_redirection(data, command);
    check_crash(data, w_status);
}

int execute_command(data_t *data, command_t *command)
{
    char *path = check_path(data, command->parsed[0]);

    command->executed = 1;
    check_redirection(command);
    if (!path && !is_builtin(command)) {
        my_put_str(clean_str(command->parsed[0]), 2);
        my_put_str(": Command not found.\n", 2);
        data->status = "1";
        return (-1);
    }
    process_exec_command(data, command, path);
    return (0);
}

void process_command(data_t *data, char *command)
{
    if (command)
        command = inhibitors(data, command);
    command = clean_str(command);
    get_all_commands(data, command);
    execute_all_command(data);
    remove_all_command(data, command);
}

void execute_all_command(data_t *data)
{
    command_t *command = data->command;
    int end = 0;

    while (command) {
        if (command->executed || compare(command->parsed[0], "exit")) {
            end = (compare(command->parsed[0], "exit")) ? 1 : 0;
            command = command->next;
            continue;
        }
        if (!command->operator || cmp_string(command->operator, "|") != 0)
            execute_command(data, command);
        else if (compare(command->operator, "|")) {
            execute_pipe(data, command);
            command->executed = 1;
        }
        if (check_separator(data, command) == true)
            break;
        command = command->next;
    }
    if (end)
        quit(data);
}
