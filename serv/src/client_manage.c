/*
** EPITECH PROJECT, 2019
** PROJECT_NAME
** File description:
** DESCRIPTION
*/

#include "server.h"

bool update_client_list(client_inf_t *client, server_inf_t *serv, fd_set *client_update)
{
    int ret = 0;
    int max = 0;
    int current = 0;

    FD_ZERO(client_update);
    FD_SET(serv->socket, client_update);
    max = serv->socket;
    for (size_t i = 0 ; i < MAX_CLIENT; i++) {
        current = client->client_list[i];
        if(current > 0)   
            FD_SET(current, client_update);
        if(current > max)   
            max = current;
    }
    ret = select(max + 1, client_update, NULL, NULL, NULL);
    if ((ret < 0) && (errno != EINTR))
        return my_str_error(ERROR_SELECT);
    return true;
}

bool new_connection(client_inf_t *client, server_inf_t *serv, fd_set *client_update)
{
    int addrlen = sizeof(serv->address);
    int new_client = 0;

    if (FD_ISSET(serv->socket, client_update)) {
        new_client = accept(serv->socket, (struct sockaddr *) &serv->address, (socklen_t *) &addrlen);
        if (new_client < 0)
            return my_str_error(ERROR_ACCEPT);
        //printf("New connection, socket fd is %d, ip is : %s, port : %d  \n", new_client, inet_ntoa(serv->address.sin_addr), ntohs (serv->address.sin_port));
        //if(send(new_client, "Welcome\n", strlen("Welcome\n"), 0) != strlen("Welcome\n"))
        //    return my_str_error(ERROR_SEND);
        for (size_t i = 0; i < MAX_CLIENT; i++) {
            if (client->client_list[i] == 0 ) {
                client->client_list[i] = new_client;
                break;
            }
        }
    }
    return true;
}

bool disconnection_manage(int *client, server_inf_t *serv)
{
    int addrlen = sizeof(serv->address);

    getpeername(*client, (struct sockaddr *) &serv->address, (socklen_t *) &addrlen);
    printf("Host disconnected, ip %s, port %d \n", inet_ntoa(serv->address.sin_addr), ntohs(serv->address.sin_port));
    close(*client);
    *client = 0;
    return true;
}