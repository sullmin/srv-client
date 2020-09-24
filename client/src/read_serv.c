/*
** EPITECH PROJECT, 2019
** PROJECT_NAME
** File description:
** DESCRIPTION
*/

#include "client.h"

void serv_read(int socket_fd)
{
    char buff[1024];
    int read_size;
    int flags = fcntl(socket_fd, F_GETFL, 0);

    canonical_mode_select(true);
    fcntl(socket_fd, F_SETFL, flags | O_NONBLOCK);
    read_size = read(socket_fd, buff, 1024);
    canonical_mode_select(false);
    if (read_size > 0) {
        buff[read_size] = '\0';
        if (read_size != 0) {
            interprate(buff);
            fprintf(stdout, "\n");
        }
    }
}