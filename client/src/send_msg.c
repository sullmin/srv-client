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

    if (trans->transmition) {
        if (strcmp(trans->transmition, EOT) == 0) {
            *enable = false;
        }
        else {
            ret = write(socket_fd, trans, sizeof(msg_t));
            if (ret != -1)
                ret = write(socket_fd, trans->transmition, trans->size);
        }
        free(trans->transmition);
    }
    return (ret == -1) ? false : true;
}

static bool make_trans(char *input, msg_t *trans)
{
    trans->type = MSG_TYPE;
    trans->transmition = input;
    trans->size = (input) ? strlen(input) : 0;
    trans->extention = NULL;
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
        if (!send_msg(socket_fd, &trans, &enable))
            return EXIT_ERROR;
    } while(enable);
    return EXIT_SUCCESS;
}