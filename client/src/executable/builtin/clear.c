/*
** EPITECH PROJECT, 2019
** PROJECT_NAME
** File description:
** DESCRIPTION
*/

#include <stdio.h>
#include "builtin_t.h"

void my_clear(builtin_t *toolsbag)
{
    fprintf(stdout, "\e[1;1H\e[2J");
    fflush(stdout);
    toolsbag->stat = SUCCESS;
}