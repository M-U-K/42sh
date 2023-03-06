/*
** EPITECH PROJECT, 2019
** my_str_to_word_array.c
** File description:
** return a array
*/

#include <shell.h>

int my_isalpha(char c)
{
    if (c < 58 && c > 47)
        return (1);
    if (c < 91 && c > 64)
        return (1);
    if (c < 123 && c > 96)
        return (1);
    return (0);
}

int count_word(char const *str, char sep)
{
    int word = 0;
    int i = 0;

    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] == sep) {
            word += 1;
        }
    }
    word += (str[i - 1] != sep) ? 1 : 0;
    return (word);
}

char *add_word(char const *str, int *first, char sep)
{
    int col = 0;
    int last = 0;
    char *result = NULL;

    for (last = *first; str[last] != sep && str[last] != '\0'; last++);
    result = malloc(last - *first + 1);
    for (col = 0; col < last - *first; col++) {
        result[col] = str[*first + col];
    }
    result[col] = '\0';
    *first += last - *first + 1;
    return (result);
}

char **my_str_to_word_array(char const *str, char sep)
{
    int first = 0;
    char **array_word;
    int word;
    int i;
    int wordnb = 0;

    if (!str)
        return (NULL);
    word = count_word(str, sep);
    array_word = malloc(sizeof(char *) * (word + 1));
    for (i = 0; i < word; i++) {
        array_word[wordnb] = add_word(str, &first, sep);
        wordnb += 1;
    }
    array_word[i] = 0;
    return (array_word);
}
