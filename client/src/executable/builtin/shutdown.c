/*
** EPITECH PROJECT, 2019
** PROJECT_NAME
** File description:
** DESCRIPTION
*/

#include "builtin_t.h"

void my_shutdown(builtin_t *toolsbag)
{
    *(toolsbag->enable) = false;
    toolsbag->stat = SUCCESS;
}