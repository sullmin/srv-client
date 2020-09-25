/*
** EPITECH PROJECT, 2019
** client.h
** File description:
** client.h
*/

#ifndef CLIENT_H
#define CLIENT_H

#include "define.h"
#include "link_t.h"
#include "tools.h"
#include "libc.h"

char *secondary_loop(int socket_fd);
int client_loop(int socket_fd);
void serv_read(int socket_fd);
void canonical_mode_select(bool enable);
void interprate(char *str);

#endif