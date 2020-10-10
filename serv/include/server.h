/*
** EPITECH PROJECT, 2019
** client.h
** File description:
** client.h
*/

#ifndef SERV_H
#define SERV_H

#include "libc.h"
#include "msg_t.h"
#include "define.h"
#include "client_inf_t.h"
#include "server_inf_t.h"

bool init_serv(server_inf_t *serv);
bool main_while(server_inf_t *serv);
bool update_client_list(client_inf_t *client, server_inf_t *serv, fd_set *client_update);
bool new_connection(client_inf_t *client, server_inf_t *serv, fd_set *client_update);
bool my_str_error(const char *str);
bool disconnection_manage(int *client, server_inf_t *serv);
bool transmition_manage(server_inf_t *serv, client_inf_t *client, fd_set client_update);

#endif
