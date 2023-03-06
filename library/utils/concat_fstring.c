/*
** EPITECH PROJECT, 2019
** Librairy
** File description:
** concat_fstring.c
*/

#include <stdio.h>

#include <stdarg.h>
#include <stdlib.h>
#include <stdbool.h>

#include "utils.h"

char *join_str(char *begin, char *end)
{
    int len = string_len(begin, '\0') + string_len(end, '\0');
    char *result = malloc(sizeof(char) * (len + 1));
    int result_ctr = 0;

    if (result == NULL)
        return (NULL);
    for (int ctr = 0; begin != NULL && begin[ctr] != '\0'; ctr += 1) {
        result[result_ctr] = begin[ctr];
        result_ctr += 1;
    }
    for (int ctr = 0; end != NULL && end[ctr] != '\0'; ctr += 1) {
        result[result_ctr] = end[ctr];
        result_ctr += 1;
    }
    result[len] = '\0';
    return (free(begin), free(end), result);
}

char *take_arg(char type, va_list args)
{
    char *str = NULL;

    switch (type) {
    case 'i':
        str = get_integer_nbr(va_arg(args, int));
        break;
    case 'c':
        str = malloc(sizeof(char) * 2);
        str[0] = va_arg(args, int);
        str[1] = '\0';
        break;
    case 's':
        str = va_arg(args, char *);
        break;
    }
    return (str);
}

char *concat_fstring(char *format, ...)
{
    va_list args;
    char *result = NULL;
    char *tmp = NULL;
    int len = 0;

    va_start(args, format);
    for (int ctr = 0; format != NULL && format[ctr] != '\0'; ctr += 1) {
        if (format[ctr] == '%') {
            ctr += 1;
            tmp = my_realloc(take_arg(format[ctr], args), 0, false, false);
        }
        else {
            len = string_len(&(format[ctr]), '%');
            tmp = my_realloc(&(format[ctr]), len, true, false);
            while (ctr++, format[ctr] != '%' && format[ctr] != '\0');
            ctr -= 1;
        }
        result = join_str(result, tmp);
    }
    va_end(args);
    return (result);
}