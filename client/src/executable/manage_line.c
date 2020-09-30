/*
** EPITECH PROJECT, 2019
** PROJECT_NAME
** File description:
** DESCRIPTION
*/

#include "client.h"

static bool is_it_exec(char *line)
{
    bool is_exec = false;
    size_t i = 0;

    for (i = 0; line[i] && (line[i] < 33 || line[i] > 126); i++);
    if (strncmp(line + i, STARTEXEC, strlen(STARTEXEC)) == 0)
        is_exec = true;
    else
        is_exec = false;
    return is_exec;
}

bool execute_line(msg_t *trans, bool *is_exec)
{
    if (trans->type == MSG_TYPE) {
        if (is_it_exec(trans->transmission)) {
            printf("NOT ALREADY DEV\n");
            *is_exec = true;
        }
    }
    return true;
}