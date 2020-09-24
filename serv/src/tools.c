/*
** EPITECH PROJECT, 2019
** PROJECT_NAME
** File description:
** DESCRIPTION
*/

#include "server.h"

bool my_str_error(const char *str)
{
    perror(str);
    return false;
}