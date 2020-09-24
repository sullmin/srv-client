/*
** EPITECH PROJECT, 2019
** server
** File description:
** server
*/

#include "server.h"

bool main_while(server_inf_t *serv)
{
    fd_set client_update;
    client_inf_t client = {0};

    for (size_t i = 0; i < MAX_CLIENT; i++, client.client_list[i] = 0);
    while (true) {
        if (!update_client_list(&client, serv, &client_update))
            return false;
        if (!new_connection(&client, serv, &client_update))
            return false;
        if (!transmition_manage(serv, &client, client_update))
            return false;
    }
    return true;
}