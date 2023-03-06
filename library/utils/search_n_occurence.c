/*
** EPITECH PROJECT, 2019
** Librairy
** File description:
** search_n_occurence.c
*/

#include "utils.h"

#include <stdbool.h>

bool check_is_an_occurence(char const *str, char const *to_find)
{
    for (int ctr = 0; str[ctr] == to_find[ctr] && str[ctr] != '\0'; ctr++)
        if (to_find[ctr + 1] == '\0')
            return (true);
    return (false);
}

int search_n_occurence(char const *str, char const *to_find, int n)
{
    int occ_find = 0;
    int last_occ = -1;
    int size_to_find = string_len(to_find, '\0');

    if (size_to_find == 0)
        return (-1);
    for (int i = 0; str[i] != '\0'; i++) {
        if (occ_find >= n && n != -1)
            return (last_occ);
        if (check_is_an_occurence(&(str[i]), to_find) == true) {
            occ_find += 1;
            last_occ = i;
            i += size_to_find - 1;
        }
    }
    return (last_occ);
}