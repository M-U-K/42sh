/*
** EPITECH PROJECT, 2019
** PSU_42sh_2019
** File description:
** check_separator.c
*/

#include "shell.h"

command_t *is_conditional_separator(command_t *actual_cmd)
{
    for (command_t *tmp = actual_cmd; tmp && tmp->operator; tmp = tmp->next) {
        if (is_a_redirection(tmp->operator) == true)
            continue;
        else if (cmp_string(tmp->operator, "||") == 0\
|| cmp_string(tmp->operator, "&&") == 0)
            return (tmp);
        else
            return (NULL);
    }
    return (NULL);
}

bool check_another_command(command_t *actual_cmd)
{
    for (command_t *tmp = actual_cmd->next; tmp && tmp->operator;
    tmp = tmp->next) {
        if (cmp_string(tmp->operator, ";") == 0)
            return (true);
    }
    return (false);
}

void move_to_next_command(command_t *actual_cmd)
{
    for (command_t *tmp = actual_cmd->next; tmp && tmp->operator;
    tmp = tmp->next) {
        tmp->executed = 1;
        if (cmp_string(tmp->operator, ";") == 0)
            break;
    }
}

bool has_other_command(command_t *cmd)
{
    if (check_another_command(cmd) == false)
        return (true);
    else
        move_to_next_command(cmd);
    return (false);
}

bool check_separator(data_t *data, command_t *cmd)
{
    command_t *tmp = is_conditional_separator(cmd);

    if (tmp == NULL)
        return (false);
    if (cmp_string(data->status, "0") == 0) {
        if (cmp_string(tmp->operator, "||") == 0) {
            if (has_other_command(cmd))
                return (true);
        }
    }
    else {
        if (cmp_string(tmp->operator, "&&") == 0) {
            if (check_another_command(cmd) == false)
                return (true);
            else
                move_to_next_command(cmd);
        }
        if (cmp_string(tmp->operator, "||") == 0)
            return (false);
    }
    return (false);
}