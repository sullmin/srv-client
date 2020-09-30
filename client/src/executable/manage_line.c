/*
** EPITECH PROJECT, 2019
** PROJECT_NAME
** File description:
** DESCRIPTION
*/

#include "client.h"

static bool is_it_exec(char *line)
{
    size_t i = 0;
    bool is_exec = false;

    for (i = 0; line[i] && (line[i] < 33 || line[i] > 126); i++);
    if (strncmp(line + i, STARTEXEC, strlen(STARTEXEC)) == 0)
        is_exec = true;
    else
        is_exec = false;
    return is_exec;
}

bool execute_line(msg_t *trans, bool *is_exec)
{
    if (trans->type == MSG_TYPE && is_it_exec(trans->transmission)) {
        if (!prepare_exec(trans->transmission))
            return false;
        *is_exec = true;
    }
    return true;
}