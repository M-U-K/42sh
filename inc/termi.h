/*
** EPITECH PROJECT, 2020
** Untitled (Workspace)
** File description:
** term
*/

#ifndef TERM_H_
#define TERM_H_

typedef struct termi_s
{
    char *cmd;
    char c;
    int pos_cmd;
    int pos_curs;
    int size_cmd;
    int size_line;
    int block_disp;
    int len_min;
    int len_max;
    int cmp;
    int cheat;
    struct termios old;
    struct termios act;
    struct termios noecho;
    int end;
    int dect;
    int term_set;
    const char *str;
}termi_t;

termi_t *init_term(void);



#endif
