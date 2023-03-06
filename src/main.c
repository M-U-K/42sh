/*
** EPITECH PROJECT, 2020
** main.c
** File description:
** main script of the shell
*/

#include "shell.h"

data_t *init_struct(char **env)
{
    data_t *data = malloc(sizeof(data_t));

    if (!data)
        return (NULL);
    data->command = NULL;
    data->last_dir = NULL;
    data->alias = NULL;
    data->var = NULL;
    data->redirection_pipe = malloc(sizeof(int) * 2);
    data->redirection = 1;
    data->nbr_env_var = 1;
    data->status = "0";
    data->env = copy_env(data, env);
    data->term = init_term();
    return (data);
}

void remove_all_command(data_t *data, char *cmd)
{
    command_t *command = data->command;
    command_t *deleted = NULL;

    if (cmd)
        free(cmd);
    while (command) {
        free(command->command);
        if (command->operator)
            free(command->operator);
        deleted = command;
        command = command->next;
        free(deleted);
    }
    data->command = NULL;
}

void quit(data_t *data)
{
    int statu = get_number(data->status);

    printf("%d;\n", statu);
    for (int i = 0; data->env[i]; i++)
        free(data->env[i]);
    free(data->env);
    free(data);
    exit(statu);
}

void set_up_term(data_t *data)
{
    tcgetattr(0, &data->term->old);
    tcgetattr(0, &data->term->act);
    tcgetattr(0, &data->term->noecho);

    data->term->noecho.c_lflag &= ~ECHO;
    data->term->noecho.c_lflag &= ~ICANON;
    data->term->noecho.c_cc[VMIN] = 1;
    data->term->noecho.c_cc[VTIME] = 0;

    data->term->act.c_lflag &= ~ICANON;
    data->term->act.c_cc[VMIN] = 1;
    data->term->act.c_cc[VTIME] = 0.1;
}

int main(int ac, char **av, char **env)
{
    data_t *data = init_struct(env);

    char *command = "";
    if (!data)
        return (84);
    set_up_term(data);
    while (data->term->end != 1) {
        print_prompt();
        ioctl(0, TCSETS, &data->term->act);
        getline_with_cursed_term(data);
        command = string_dup(data->term->cmd);
        process_command(data, command);
        remove_all_command(data, command);
    }
    endwin();
    return (get_number(data->status));
}