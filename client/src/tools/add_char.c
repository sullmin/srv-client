/*
** EPITECH PROJECT, 2019
** PROJECT_NAME
** File description:
** DESCRIPTION
*/

#include <stdlib.h>
#include <string.h>

static char *malloc_size(char *str)
{
    char *ret;

    if (str)
        ret = malloc(sizeof(char) * (strlen(str) + 3));
    else
        ret = malloc(sizeof(char) * 2);
    return ret;
}

char *add_char(char *str, char c)
{
    char *ret;
    size_t i = 0;
    size_t move = 0;

    ret = malloc_size(str);
    if (!ret)
        return NULL;
    for (i = 0; str && str[move] != '\0'; i++) {
        ret[i] = str[move];
        move++;
    }
    ret[i++] = c;
    ret[i] = '\0';
    if (str)
        free(str);
    return ret;
}