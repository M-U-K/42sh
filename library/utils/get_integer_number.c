/*
** EPITECH PROJECT, 2019
** Librairy
** File description:
** get_integer_number.c
*/

#include <stdlib.h>
#include <stdbool.h>

bool calc_pow_len_and_check_is_neg(int *nb, int *pow, int *len)
{
    bool is_neg = false;

    (*nb < 0) ? (is_neg = true, *nb *= -1, *len += 1) : (is_neg = false);
    for (int temp_nb = *nb; temp_nb > 9; temp_nb /= 10) {
        *len += 1;
        *pow *= 10;
    }
    return (is_neg);
}

char *get_integer_nbr(int nb)
{
    int ctr = 0;
    int len = 1;
    int pow = 1;
    bool is_neg = calc_pow_len_and_check_is_neg(&nb, &pow, &len);
    char *result = NULL;

    result = malloc(sizeof(char) * (len + 1));
    if (result == NULL)
        return (NULL);
    (is_neg == true) ? (result[0] = '-', ctr = 1) : (ctr = 0);
    while (pow > 0) {
        result[ctr] = ((nb / pow) + 48);
        nb %= pow;
        pow /= 10;
        ctr += 1;
    }
    result[len] = '\0';
    return (result);
}