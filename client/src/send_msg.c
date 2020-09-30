/*
** EPITECH PROJECT, 2019
** send_msg
** File description:
** send_msg
*/

#include "client.h"

static bool send_msg(int socket_fd, msg_t *trans, bool *enable)
{
    int ret = 0;

    if (trans->transmission) {
        if (strcmp(trans->transmission, EOT) == 0) {
            *enable = false;
        }
        else {
            ret = write(socket_fd, trans, sizeof(msg_t));
            if (ret != -1)
                ret = write(socket_fd, trans->transmission, trans->size);
        }
    }
    return (ret == -1) ? false : true;
}

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

    if (!execute_line(trans, &is_exec))
        return false;
    if (!is_exec)
        if (!send_msg(socket_fd, trans, enable))
            return false;
    if (trans->transmission)
        free(trans->transmission);
    return true;
}

int client_loop(int socket_fd)
{
    msg_t trans = {0};
    char *input = NULL;
    bool enable = true;

    do {
        input = secondary_loop(socket_fd);
        if (!make_trans(input, &trans))
            return EXIT_ERROR;
        if (!execution_road(socket_fd, &trans, &enable))
            return EXIT_ERROR;
    } while(enable);
    return EXIT_SUCCESS;
}