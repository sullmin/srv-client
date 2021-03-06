/*
** EPITECH PROJECT, 2019
** send_msg
** File description:
** send_msg
*/

#include "client.h"

static bool make_trans(char *input, msg_t *trans)
{
    trans->type = MSG_TYPE;
    trans->transmission = input;
    trans->size = (input) ? strlen(input) : 0;
    trans->extention = NULL;
    return true;
}

static bool execution_road(int socket_fd, msg_t *trans, bool *enable)
{
    bool is_exec = false;

    if (!trans->transmission)
        return true;
    if (strlen(trans->transmission) != 0) {
        if (!execute_line(trans, &is_exec, enable, socket_fd))
            return false;
        if (!is_exec && !send_msg(socket_fd, trans))
            return false;
    }
    free(trans->transmission);
    return true;
}

bool send_msg(int socket_fd, msg_t *trans)
{
    int ret = 0;

    if (trans->transmission) {
        ret = write(socket_fd, trans, sizeof(msg_t));
        if (ret != -1)
            ret = write(socket_fd, trans->transmission, trans->size);
    }
    return (ret == -1) ? false : true;
}

int client_loop(int socket_fd)
{
    msg_t trans = {0};
    char *input = NULL;
    bool enable = true;

    do {
        input = secondary_loop(socket_fd, &enable);
        if (!make_trans(input, &trans))
            return EXIT_ERROR;
        if (!execution_road(socket_fd, &trans, &enable))
            return EXIT_ERROR;
    } while(enable);
    return EXIT_SUCCESS;
}