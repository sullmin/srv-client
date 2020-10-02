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

static void prepare_builtin(builtin_t *to_build, bool *enable, int socket_fd)
{
    to_build->stat = NOTSET;
    to_build->serv_fd = socket_fd;
    to_build->params = NULL;
    to_build->to_exec = NULL;
    to_build->enable = enable;
}

bool execute_line(msg_t *trans, bool *is_exec, bool *enable, int socket_fd)
{
    size_t offset = strlen(STARTEXEC);
    builtin_t toolsbag = {0};

    if (trans->type == MSG_TYPE && is_it_exec(trans->transmission)) {
        prepare_builtin(&toolsbag, enable, socket_fd);
        if (!execution_manage(trans->transmission + offset, &toolsbag))
            return false;
        *is_exec = true;
    }
    return true;
}