/*
** EPITECH PROJECT, 2020
** Untitled (Workspace)
** File description:
** init
*/

#include "shell.h"



void gest_move_cursor2(data_t *data)
{
    char *tgoto(const char *cap, int col, int row);
    char *cm_cap = tgetstr("cm", NULL);
    int len = tgetnum("li");

    if (data->term->pos_curs > data->term->len_min && \
data->term->c == 68 && data->term->dect == 1) {
        data->term->cheat = 1;
        data->term->pos_cmd--;
        data->term->pos_curs--;
        clean_line(data);
        printf_prompt();
        printf(data->term->cmd, 1);
        tputs(tgoto(cm_cap, data->term->pos_curs, len), 1, putchar);
        data->term->dect = 0;
    }
}

void set_up_cursed_term(data_t *data)
{
    data->term->cmd = "";
    ioctl(0, TCSETS, &data->term->act);
    data->term->pos_curs += 6;
    data->term->pos_curs += string_len(get_current_path(1), '\0');
    data->term->size_line += 6;
    data->term->size_line += string_len(get_current_path(1), '\0');
    data->term->len_min = data->term->pos_curs;
    data->term->len_max = data->term->size_line-1;
}

char *getline_with_cursed_term(data_t *data)
{
    char *cm_cap = tgetstr("cm", NULL);
    int len = tgetnum("li");

    (void)cm_cap;
    set_up_cursed_term(data);
    while (data->term->end != 1) {
        do_random_things(data);
        if (data->term->c == 27)
            data->term->dect = 1;
        remove_function(data);
        gest_move_cursor(data);
        if (data->term->c == 4) {
            data->term->end = 1;
            ioctl(0, TCSETS, &data->term->old);
        }
        if (enter_cmd(data) != NULL)
            return (data->term->cmd);
        del_function(data);
    }
    ioctl(0, TCSETS, &data->term->old);
    return (NULL);
}

termi_t *init_term(void)
{
    termi_t *new = malloc(sizeof(termi_t));
    new->pos_cmd = 0;
    new->str = "";
    new->cmd = "";
    new->size_cmd = 1;
    new->size_line = 1;
    new->block_disp = 0;
    new->cheat = 0;
    new->pos_curs = 0;
    new->cmp = 0;
    new->end = 0;
    new->c = 0;
    new->dect = 0;
    new->term_set = 0;
    return (new);
}
