/*
** EPITECH PROJECT, 2020
** str_is_alphanum.c
** File description:
** is_alpha
*/

int is_alphanum(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if ((str[i] >= 'a' && str[i] <= 'z') || \
(str[i] >= 'A' && str[i] <= 'Z') \
|| (str[i] >= '0' && str[i] <= '9') || str[i] == '_')
            continue;
        else
            return (0);
    }
    return (1);
}