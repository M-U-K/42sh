/*
** EPITECH PROJECT, 2020
** Untitled (Workspace)
** File description:
** move
*/

#include "shell.h"

void gest_move_cursor(data_t *data)
{
    char *tgoto(const char *cap, int col, int row);
    char *cm_cap = tgetstr("cm", NULL);
    int len = tgetnum("li");

    gest_move_cursor2(data);
    if (data->term->pos_curs < data->term->len_max && \
data->term->c == 67 && data->term->dect == 1) {
        data->term->cheat = 1;
        data->term->pos_cmd++;
        data->term->pos_curs++;
        clean_line(data);
        printf_prompt();
        printf(data->term->cmd, 1);
        tputs(tgoto(cm_cap, data->term->pos_curs, len), 1, putchar);
        data->term->dect = 0;
    }
}

void use_cheat_mode(data_t *data)
{
    char *tgoto(const char *cap, int col, int row);
    char *cm_cap = tgetstr("cm", NULL);
    int len = tgetnum("li");

    if (data->term->c >= 32 && data->term->c <= 127 \
&& data->term->block_disp >= 0) {
        if (data->term->cheat == 1) {
            clean_line(data);
            printf_prompt();
            printf("%s", data->term->cmd);
            tputs(tgoto(cm_cap, data->term->pos_curs, len), 1, putchar);
        }
    }
}

void setterm_cheat_active(data_t *data)
{
    char *cm_cap = tgetstr("cm", NULL);
    int len = tgetnum("li");
    (void)cm_cap;
    (void)len;
    if (data->term->cheat == 1 && data->term->term_set == 0) {
        setupterm(NULL, STDIN_FILENO, NULL);
        data->term->term_set = 1;
        cm_cap = tgetstr("cm", NULL);
        len = tgetnum("li");
    }
}

void del_function(data_t *data)
{
    if (data->term->c >= 32 && data->term->c <= 126 && \
data->term->block_disp >= 0 && data->term->c != 4) {
        if (data->term->c != 10 && data->term->c != 4) {
            data->term->cmd = add_char_line(data, data->\
term->cmd, data->term->pos_cmd, data->term->c);
            data->term->str = NULL;
            data->term->str = concat_fstring("%s%c", \
data->term->str, data->term->c);
        }
    }
}
