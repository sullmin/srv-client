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
#include "msg_t.h"
#include "builtin_t.h"
#include "libc.h"

//CLIENT

char *secondary_loop(int socket_fd);
int client_loop(int socket_fd);
void serv_read(int socket_fd);
void canonical_mode_select(bool enable);

//INTERPRATE

void interprate(char *str);

//EXECUTABLE | BUILTIN

bool execute_line(msg_t *trans, bool *is_exec, bool *enable, int socket_fd);
bool execution_manage(char *line, builtin_t *toolsbag);

/*== BUILTIN ==*/
void clear(__attribute__((unused)) char **params);

#endif