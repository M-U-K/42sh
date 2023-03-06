/*
** EPITECH PROJECT, 2020
** Untitled (Workspace)
** File description:
** add
*/

#include "shell.h"

void clean_line(data_t *data)
{
    char *mv_curs = tgetstr("cm", NULL);
    int len = tgetnum("li");

    tputs(tgoto(mv_curs, data->term->size_line+3, len), 1, putchar);
    for (int i = data->term->size_line+3; i > 0; i --) {
        putp(concat_fstring("%c", 27));
        putp(concat_fstring("%c", 91));
        putp(concat_fstring("%c", 68));
        putp(" ");
        putp(concat_fstring("%c", 27));
        putp(concat_fstring("%c", 91));
        putp(concat_fstring("%c", 68));
    }
}

void add_setting_term(data_t *data)
{
    data->term->pos_cmd ++;
    data->term->size_cmd++;
    data->term->size_line++;
    data->term->pos_curs++;
    data->term->len_max++;
}

char *add_char_line(data_t *data, char *cmd, int pos_add, char c)
{
    int i = 0;
    int x = 0;
    char *str = malloc(sizeof(char) * (pos_add+2));
    char *str2;

    if (cmd != NULL)
        str2 = malloc(sizeof(char) * strlen(cmd) - pos_add+1);
    for (; i != pos_add; i++)
        str[i] = cmd[i];
    str[i] = c;
    str[i+1] = '\0';
    if (str2 != NULL && cmd[pos_add] != '\0') {
        for (int y = pos_add; cmd[y] != '\0'; y++, x++)
            str2[x] = cmd[y];
        str2[x] = '\0';
        str = concat_fstring("%s%s", str, str2);
    }
    add_setting_term(data);
    return (str);
}

void printf_prompt(void)
{
    char *path = get_current_path(1);

    if (isatty(0)) {
        printf("[");
        printf("%s", path);
        printf("] §> ");
    }
    free(path);
}

char *remove_char_line(data_t *data, char *cmd, int pos)
{
    (void)data;
    pos -= string_len(get_current_path(1), '\0');
    pos -= 6;
    char *str = malloc(sizeof(char) * strlen(cmd));
    int y = 0;
    for (int i = 0; cmd[i] != '\0'; i++, y++) {
        if (i != pos) {
            str[y] = cmd[i];

        }
        if (i == pos)
            y--;
    }
    str[y] = '\0';
    return (str);
}