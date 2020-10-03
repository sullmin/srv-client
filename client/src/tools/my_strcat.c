/*
** EPITECH PROJECT, 2019
** strcat
** File description:
** strcat
*/

#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

static size_t get_size(const va_list save_list, const size_t nb_str)
{
    char *tmp = NULL;
    size_t size = 0;

    for (size_t u = 0; u < nb_str; u++) {
        tmp = va_arg(save_list, char *);
        if (tmp)
            size += strlen(tmp);
    }
    return size;
}

static void concat(char *dest, const char *src)
{
    size_t index = 0;

    for (index = 0; dest[index]; index++);
    for (size_t u = 0; src[u]; u++, index++)
        dest[index] = src[u];
    dest[index] = '\0';
}

static void loop_cat(const va_list str_list, const size_t nb_str, char *str_cat)
{
    char *tmp = NULL;

    for (size_t u = 0; u < nb_str; u++) {
        tmp = va_arg(str_list, char *);
        if (tmp)
            concat(str_cat, tmp);
    }
}

char *str_dup_cat(size_t nb_str, ... )
{
    char *str_cat = NULL;
    size_t size = 0;

    va_list str_list;
    va_list save_list;
    va_start(str_list, nb_str);
    va_copy(save_list, str_list);
    if (nb_str <= 0)
        return NULL;
    size = get_size(save_list, nb_str);
    va_end(save_list);
    str_cat = malloc(sizeof(char) * (size + 1));
    if (!str_cat)
        return NULL;
    str_cat[0] = '\0';
    loop_cat(str_list, nb_str, str_cat);
    va_end(str_list);
    return str_cat;
}