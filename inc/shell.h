/*
** EPITECH PROJECT, 2020
** shell.h
** File description:
**
*/

#ifndef PSU_MY_EXEC2_2019_SHELL
#define PSU_MY_EXEC2_2019_SHELL

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/ioctl.h>
#include <fcntl.h>
#include <termios.h>
#include <sys/ioctl.h>
#include <curses.h>
#include <termi.h>
#include <term.h>
#undef tab

#include "utils.h"
#include "printf.h"

typedef struct alias_s
{
    char *alias;
    char *command;
    struct alias_s *prev;
    struct alias_s *next;
} alias_t;

typedef struct local_s
{
    char *local;
    char *value;
    struct local_s *prev;
    struct local_s *next;
} local_t;

typedef struct command_s
{
    char *command;
    char *operator;
    char **parsed;
    int arg;
    int executed;
    struct command_s *next;
}command_t;

typedef struct data_s
{
    char **env;
    int nbr_env_var;
    char *last_dir;
    int redirection;
    int *redirection_pipe;
    command_t *command;
    alias_t *alias;
    local_t *var;
    char *status;
    termi_t *term;
} data_t;

//Utils
int my_put_str(char *str, int channel);
char *clean_str(char *str);
char *my_str_dup(char const *src);
int start_with(char const *str, char const *start);
char **my_str_to_word_array(char const *str, char sep);
char *my_str_cat(char const *dest, char const *src);
int my_str_len(char const *str);
int compare(char const *str1, char const *str2);
int is_alphanum(char const *str);

//Shell
void print_prompt(void);
char **copy_env(data_t *data, char **env);
char *get_env_var(data_t *data, char *var);
void get_all_commands(data_t *data, char *line);
int execute_pipe(data_t *data, command_t *command);
void execute_all_command(data_t *data);
char *check_path(data_t *data, char *cmd);
void quit(data_t *data);
void remove_all_command(data_t *data, char *cmd);
void process_command(data_t *data, char *command);
char *get_current_path(int cut);
void check_crash(data_t *data, int w_status);
int execute_command(data_t *data, command_t *command);
void prepare_redirection(data_t *data, command_t *command);
void close_redirection(data_t *data, command_t *command);
bool is_a_redirection(char const *redirection);
void check_redirection(command_t *cmd);
char *inhibitors(data_t *data, char *str);
void print_command_error(data_t *data, command_t *command, char *path);
bool check_separator(data_t *data, command_t *cmd);
int error_env(data_t *data, command_t *command);
int check_other_error(data_t *data, command_t *command);
int check_bin(data_t *data, command_t *command, char *path);

//builtin
int display_env(data_t *data);
int is_builtin(command_t *command);
int set_env(data_t *data, command_t *command);
int unset_env(data_t *data, command_t *command);
void define_var(data_t *data, char **parsed_command);
int change_dir(data_t *data, command_t *command);
void execute_builtin(data_t *data, command_t *command);
int alias(data_t *data, command_t *command);
int unalias(data_t *data, command_t *command);
void change_alias(data_t *data, command_t *command);
int set_local(data_t *data, command_t *command);
int unset_local(data_t *data, command_t *command);
int change_var(data_t *data, command_t *command);

//term
char *remove_char_line(data_t *data, char *cmd, int pos);
void printf_prompt(void);
char *add_char_line(data_t *data, char *cmd, int pos_add, char c);
void add_setting_term(data_t *data);
void clean_line(data_t *data);
void del_function(data_t *data);
void setterm_cheat_active(data_t *data);
void use_cheat_mode(data_t *data);
void gest_move_cursor(data_t *data);
char *enter_cmd(data_t *data);
void do_random_things(data_t *data);
void remove_function(data_t *data);
void gest_move_cursor2(data_t *data);
char *getline_with_cursed_term(data_t *data);

#endif //PSU_MY_EXEC2_2019_SHELL
