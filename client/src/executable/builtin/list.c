/*
** EPITECH PROJECT, 2019
** PROJECT_NAME
** File description:
** DESCRIPTION
*/

#include <stdio.h>
#include "builtin_link_t.h"

extern const builtin_link_t BUILTIN_LIST[];

void my_list(builtin_t *toolsbag)
{
    fprintf(stdout, "This is the builtin's list :\n");
    for (size_t i = 0; BUILTIN_LIST[i].name[0]; i++)
        fprintf(stdout, "- %s\n", BUILTIN_LIST[i].name);
    toolsbag->stat = SUCCESS;
}