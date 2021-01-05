/*
** EPITECH PROJECT, 2019
** PROJECT_NAME
** File description:
** DESCRIPTION
*/

#include "server.h"

bool init_serv(server_inf_t *serv)
{
    int opt_val = true;
    int ret = 0;

    serv->socket = socket(AF_INET, SOCK_STREAM, 0);
    if (serv->socket == 0)
        return my_str_error(ERROR_SET);
    ret = setsockopt(serv->socket, SOL_SOCKET, (SO_REUSEADDR | SO_REUSEPORT), &opt_val, sizeof(opt_val));
    if (ret < 0)
        return my_str_error(ERROR_SETOPT);
    serv->address.sin_family = AF_INET;
    serv->address.sin_addr.s_addr = INADDR_ANY;
    serv->address.sin_port = htons(serv->port);
    ret = bind(serv->socket, (struct sockaddr *)&serv->address, sizeof(serv->address));
    if (ret < 0)
        return my_str_error(ERROR_BIND);
    ret = listen(serv->socket, 3);
    if (ret < 0)
        return my_str_error(ERROR_LISTEN);
    return true;
}