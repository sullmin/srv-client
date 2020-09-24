/*
** EPITECH PROJECT, 2019
** PROJECT_NAME
** File description:
** DESCRIPTION
*/

#include "server.h"

bool send_transmition(client_inf_t *client, size_t offset, char *buffer)
{
    fprintf(stdout, "%s\n", buffer);
    for (size_t u = 0; u < MAX_CLIENT; u++) {
        if (offset != u && client->client_list[u] != 0) {
            if (send(client->client_list[u], buffer, strlen(buffer), 0) == -1)
                return false;
        }
    }
    return true;
}

bool transmition_manage(server_inf_t *serv, client_inf_t *client, fd_set client_update)
{
    bool ret = true;
    char buffer[1025];
    int read_size = 0;

    for (size_t i = 0; i < MAX_CLIENT; i++) {
        if (FD_ISSET(client->client_list[i], &client_update)) {
            read_size = read(client->client_list[i], buffer, 1024);
            buffer[read_size] = '\0';
            if (read_size == 0) {
                ret = disconnection_manage(&client->client_list[i], serv);
            }
            else {
                ret = send_transmition(client, i, buffer);
            }
            if (!ret)
                return false;
        }
    }
    return true;
}