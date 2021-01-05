/*
** EPITECH PROJECT, 2019
** PROJECT_NAME
** File description:
** DESCRIPTION
*/

#include "client.h"

bool strisnum(const char *str)
{
    if (!str || strlen(str) == 0)
        return false;
    for (size_t i = 0; str[i]; i++)
        if (!(str[i] >= '0' && str[i] <= '9' ))
            return false;
    return true;
}