/*
** EPITECH PROJECT, 2020
** my_str_len.c
** File description:
** get len of a string
*/

int my_str_len(char const *str)
{
    int len = 0;

    if (!str)
        return (0);
    for (len = 0; str[len] != '\0'; len++);
    return (len);
}