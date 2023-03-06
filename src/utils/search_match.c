/*
** EPITECH PROJECT, 2020
** search_match.c
** File description:
** research
*/

int start_with(char const *str, char const *start)
{
    if (!str || !start)
        return (0);
    for (int i = 0; start[i] != '\0'; i++) {
        if (str[i] != start[i])
            return (0);
    }
    return (1);
}