/*
** EPITECH PROJECT, 2019
** PROJECT_NAME
** File description:
** DESCRIPTION
*/

#include "client.h"

void my_shutdown(builtin_t *toolsbag)
{
    *(toolsbag->enable) = false;
    fprintf(stdout, "%s%s\n", "\33[2K\r", DISCONNECTED);
    toolsbag->stat = SUCCESS;
}