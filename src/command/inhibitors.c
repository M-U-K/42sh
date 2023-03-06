/*
** EPITECH PROJECT, 2020
** inhibitors.c
** File description:
** manage inhibitors and replace env variable / special case by value
*/

#include "shell.h"

char *get_value(char *str, data_t *data)
{
    char *var = strdup(str);
    char *value = NULL;

    str[0] == '~' ? (var = "HOME\0"): (var = &var[1]);
    for (int i = 0; var[i] != '\0'; i++) {
        if ((var[i] <= 'A' || var[i] >='Z') && var[i] != '_') {
            var[i] = '\0';
            break;
        }
    }
    value = get_env_var(data, var);
    for (int i = 0; value && value[i] != '\0'; i++) {
        if (value[i] == '=') {
            value = &value[i + 1];
            break;
        }
    }
    if (compare(str, "$?"))
        value = data->status;
    return (value);
}

char *change_mem(char *output, char *value, int len[2])
{
    output = realloc(output, len[0] + 1);
    strcat(output, value);
    return (output);
}

char *inhibitors(data_t *data, char *str)
{
    int len[2];
    int index = 0;
    char *output = malloc(sizeof(char) * (len[0] = strlen(str) + 1));
    char *value = NULL;

    for (int i = 0; str[i] != '\0' && str[i] != '\n'; i++, index++) {
        if ((str[i] == '$' || str[i] == '~') && (i > 0 && str[i - 1] != '\\')) {
            value = get_value(&str[i], data);
            if (!value)
                return (str);
            len[0] = len[0] + (len[1] = strlen(value));
            output[index] = '\0';
            output = change_mem(output, value, len);
            index += len[1] - 1;
            for (i++; (str[i] >= 'A' && str[i] <= 'Z') || str[i] == '_'; i++);
            continue;
        }
        output[index] = str[i];
    }
    output[index] = '\0';
    return (output);
}
