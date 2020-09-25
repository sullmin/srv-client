/*
** EPITECH PROJECT, 2019
** send_msg
** File description:
** send_msg
*/

#include "client.h"

static bool send_msg(int socket_fd, char *message, bool *enable)
{
    int ret = 0;

    if (message) {
        if (strcmp(message, EOT) == 0) {
            *enable = false;
        }
        else {
            //fprintf(stderr, "%i : %s\n", strlen(message), message);
            ret = send(socket_fd, message, strlen(message), 0);
        }
        free(message);
    }
    return (ret == -1) ? false : true;
}

int client_loop(int socket_fd)
{
    char *message = NULL;
    bool enable = true;

    do {
        message = secondary_loop(socket_fd);
        if (!send_msg(socket_fd, message, &enable))
            return EXIT_ERROR;
    } while(enable);
    return EXIT_SUCCESS;
}