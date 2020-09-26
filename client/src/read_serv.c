/*
** EPITECH PROJECT, 2019
** PROJECT_NAME
** File description:
** DESCRIPTION
*/

#include "client.h"

static bool manage_receipt(int socket_fd, msg_t *tr)
{
    int read_size = 0;
    char *load = (tr->size > 0) ? malloc(sizeof(char) * (tr->size + 1)) : NULL;

    if (!load)
        return false;
    usleep(100);
    read_size = read(socket_fd, load, tr->size);
    if (read_size > 0) {
        if (tr->type == MSG_TYPE) {
            load[read_size] = '\0';
            interprate(load);
        }
        else if (tr->type == FILE_TYPE) {
            fprintf(stdout, "%s", "Actually Not Dev");
        }
        fprintf(stdout, "\n");
    }
    free(load);
    return true;
}

void serv_read(int socket_fd)
{
    msg_t receipt = {0};
    int read_size;
    int flags = fcntl(socket_fd, F_GETFL, 0);

    canonical_mode_select(true);
    fcntl(socket_fd, F_SETFL, flags | O_NONBLOCK);
    read_size = read(socket_fd, &receipt, sizeof(msg_t));
    if (read_size > 0) {
        manage_receipt(socket_fd, &receipt);
    }
    canonical_mode_select(false);
}