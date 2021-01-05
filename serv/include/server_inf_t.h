/*
** EPITECH PROJECT, 2019
** client.h
** File description:
** client.h
*/

#ifndef SERVER_INF_T_H
#define SERVER_INF_T_H

#include "libc.h"

typedef struct server_inf_s
{
    int port;
    int socket;
    struct sockaddr_in address;
} server_inf_t;

#endif
