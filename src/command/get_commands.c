/*
** EPITECH PROJECT, 2020
** get_commands.c
** File description:
** get all command from input
*/

#include "shell.h"

const char *operator[] = {">>", "<<", "||", "&&", "|", "<", ">", ";", NULL};
const int op_len[] = {2, 2, 2, 2, 1, 1, 1, 1, -1};

static int is_operator(char const *str)
{
    for (int i = 0; operator[i] != NULL; i++)
        if (search_n_occurence(str, operator[i], 1) == 0)
            return (i + 1);
    return (0);
}

static void get_operator(command_t *new_command, char const *line, int end)
{
    int len = 0;
    int index = 0;

    if (is_operator(&(line[end]))) {
        len = op_len[is_operator(&(line[end])) - 1];
        new_command->operator = malloc(sizeof(char) * (len + 1));
        for (int i = end; i < end + len; i++) {
            new_command->operator[index] = line[i];
            index += 1;
        }
        new_command->operator[len] = '\0';
    }
}

void define_other_command_value(command_t *new_command)
{
    int arg = 0;

    if (new_command->parsed == NULL) {
        new_command->parsed = malloc(sizeof(char *) * 1);
        new_command->parsed[0] = NULL;
    }
    for (arg = 0; new_command->parsed[arg]; arg++);
    new_command->arg = arg;
    new_command->next = NULL;
}

static command_t *add_command(data_t *data, char const *line, int start,
int end)
{
    command_t *new_command = malloc(sizeof(command_t));
    int real_end = end;

    if (line[end + 1] == '\0' && !is_operator(&(line[end])))
        real_end += 1;
    new_command->command = NULL;
    new_command->operator = NULL;
    new_command->executed = 0;
    new_command->command = malloc(sizeof(char) * (real_end - start + 1));
    new_command->command[real_end - start] = '\0';
    for (int i = 0; i < real_end - start; i++)
        new_command->command[i] = line[start + i];
    new_command->command = clean_str(new_command->command);
    new_command->parsed = str_to_tab(new_command->command, " \n");
    change_var(data, new_command);
    change_alias(data, new_command);
    get_operator(new_command, line, real_end);
    define_other_command_value(new_command);
    return (new_command);
}

void get_all_commands(data_t *data, char *line)
{
    int start = 0;
    command_t *last_cmd = data->command;

    for (int i = 0; line[i] != '\0'; i++) {
        if (is_operator(&(line[i])) || line[i + 1] == '\0') {
            if (last_cmd && last_cmd->next)
                last_cmd = last_cmd->next;
            if (!last_cmd) {
                data->command = add_command(data, line, start, i);
                last_cmd = data->command;
                i += (last_cmd->operator) ? my_str_len(last_cmd->operator) : 0;
            } else {
                last_cmd->next = add_command(data, line, start, i);
                i += (last_cmd->next->operator) ?\
my_str_len(last_cmd->next->operator) : 0;
            }
            start = i;
        }
    }
}
