/*
** EPITECH PROJECT, 2020
** redirection.c
** File description:
** create redirection
*/

#include "shell.h"

bool has_redirect(command_t *command, int *fd, int *option)
{
    if (cmp_string(command->operator, ">>") == 0) {
        *fd = open(command->next->parsed[0], O_WRONLY | O_APPEND | O_CREAT
        , S_IRWXU | S_IXGRP | S_IRGRP | S_IROTH | S_IXOTH);
        return (true);
    }
    if (cmp_string(command->operator, ">") == 0) {
        *fd = open(command->next->parsed[0], O_WRONLY | O_TRUNC | O_CREAT
        , S_IRWXU | S_IXGRP | S_IRGRP | S_IROTH | S_IXOTH);
        return (true);
    }
    if (cmp_string(command->operator, "<") == 0) {
        *fd = open(command->next->parsed[0], O_RDONLY);
        *option = 2;
        return (true);
    }
    return (false);
}

void prepare_redirection(data_t *data, command_t *command)
{
    int fd = 0;
    int option = 1;

    (void)data;
    if (!command || !command->operator ||\
is_a_redirection(command->operator) == false)
        return;
    if (!has_redirect(command, &fd, &option))
        return;
    if (fd == -1) {
        print_error("Error: Can't redirect\n");
        return;
    }
    if (option == 1) {
        dup2(1, 0);
        dup2(fd, 1);
        close(fd);
    } else
        dup2(fd, 0);
}

void close_redirection(data_t *data, command_t *command)
{
    (void)data;
    if (!command || !command->operator ||\
is_a_redirection(command->operator) == false)
        return;
    command->next->executed = 1;
}

void check_redirection(command_t *cmd)
{
    int fd = 0;

    if (!cmd || !cmd->operator ||\
is_a_redirection(cmd->operator) == false)
        return;
    if (cmd->next != NULL && cmd->next->operator != NULL)
        if (is_a_redirection(cmd->operator) == true
        && cmp_string(cmd->next->operator, "|") == 0) {
            printf("Ambiguous output redirect.\n");
            return;
        }
    if (cmp_string(cmd->operator, ">>") == 0
    || cmp_string(cmd->operator, ">") == 0) {
        fd = open(cmd->next->parsed[0], O_CREAT
        , S_IRWXU | S_IXGRP | S_IRGRP | S_IROTH | S_IXOTH);
        close(fd);
    }
}