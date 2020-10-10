/*
** EPITECH PROJECT, 2019
** PROJECT_NAME
** File description:
** DESCRIPTION
*/

#include "client.h"

char *get_time_in_str(void)
{

    time_t act_time = time(NULL);
    char *time_in_str = ctime(&act_time);

    if (!time_in_str)
        return NULL;
    if (time_in_str[strlen(time_in_str) - 1] == '\n')
        time_in_str[strlen(time_in_str) - 1] = '\0';
    return time_in_str;
}