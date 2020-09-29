/*
** EPITECH PROJECT, 2019
** tools.h
** File description:
** tools.h
*/

#ifndef TOOLS_H
#define TOOLS_H

#include <stdbool.h>

bool my_str_error(const char *str);
char *add_char(char *str, char c);
int my_str_error_int(const char *str);
char **my_str_to_word_array(const char *str, const char *char_list,
    const bool stat);

#endif