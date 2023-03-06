/*
** EPITECH PROJECT, 2020
** Untitled (Workspace)
** File description:
** function
*/

#include "shell.h"

void remove_function(data_t *data)
{
    if (data->term->pos_curs > \
data->term->len_min && data->term->c == 127) {
        data->term->cheat = 1;
        setterm_cheat_active(data);
        data->term->pos_cmd--;
        data->term->len_max--;
        data->term->pos_curs--;
        putp(concat_fstring("%c", 27));
        putp(concat_fstring("%c", 91));
        putp(concat_fstring("%c", 68));
        putp(" ");
        putp(concat_fstring("%c", 27));
        putp(concat_fstring("%c", 91));
        putp(concat_fstring("%c", 68));
        data->term->cmd = remove_char_line\
(data, data->term->cmd, data->term->pos_curs);
    }
}

void do_random_things(data_t *data)
{
    char *cm_cap = tgetstr("cm", NULL);
    int len = tgetnum("li");

    (void)cm_cap;
    data->term->block_disp ++;
    if (data->term->c == 27)
        data->term->block_disp = -2;
    if (data->term->c == 127 || data->term->c == 27)
        data->term->cheat = 1;
    use_cheat_mode(data);
    data->term->c = getchar();
    if (data->term->cheat == 1 && data->term->term_set == 0) {
        setupterm(NULL, STDIN_FILENO, NULL);
        data->term->term_set = 1;
        cm_cap = tgetstr("cm", NULL);
        len = tgetnum("li");
    }
    if (data->term->c == -1) {
        data->term->end =1;
        ioctl(0, TCSETS, &data->term->old);
    }
}

char *enter_cmd(data_t *data)
{
    if (data->term->c == 10) {
        data->term->pos_cmd = 0;
        data->term->str = "";
        data->term->size_cmd = 1;
        data->term->size_line = 1;
        data->term->c = 0;
        data->term->block_disp = 1;
        data->term->pos_curs = 0;
        ioctl(0, TCSETS, &data->term->old);
        return (data->term->cmd);
    }
    return (NULL);
}