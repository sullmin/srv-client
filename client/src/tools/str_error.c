/*
** EPITECH PROJECT, 2019
** PROJECT_NAME
** File description:
** DESCRIPTION
*/

#include <stdio.h>
#include <stdbool.h>
#include "define.h"

bool my_str_error(const char *str)
{
    perror(str);
    return false;
}

int my_str_error_int(const char *str)
{
    perror(str);
    return EXIT_ERROR;
}