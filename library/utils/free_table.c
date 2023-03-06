/*
** EPITECH PROJECT, 2019
** Librairy
** File description:
** free_table.c
*/

#include <stdlib.h>

void free_tab(char **tab)
{
    if (tab == NULL)
        return (free(tab));
    for (int ctr = 0; tab[ctr] != NULL; ctr += 1)
        free(tab[ctr]);
    free(tab);
}