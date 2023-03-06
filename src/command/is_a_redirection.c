/*
** EPITECH PROJECT, 2019
** PSU_42sh_2019
** File description:
** is_a_redirection.c
*/

#include "shell.h"

bool is_a_redirection(char const *redirection)
{
    if (cmp_string(redirection, ">") == 0\
|| cmp_string(redirection, "<") == 0\
|| cmp_string(redirection, ">>") == 0\
|| cmp_string(redirection, "<<") == 0)
        return (true);
    return (false);
}