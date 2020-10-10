/*
** EPITECH PROJECT, 2019
** client.h
** File description:
** client.h
*/

#ifndef CLIENT_H
#define CLIENT_H

#include "builtin_link_t.h"
#include "builtin_t.h"
#include "define.h"
#include "link_t.h"
#include "tools.h"
#include "msg_t.h"
#include "libc.h"

//CLIENT

void serv_read(int socket_fd);
int client_loop(int socket_fd);
char *secondary_loop(int socket_fd);
void canonical_mode_select(bool enable);
bool send_msg(int socket_fd, msg_t *trans);

//INTERPRATE

void interprate(char *str, bool type);

//EXECUTABLE | BUILTIN

bool execute_line(msg_t *trans, bool *is_exec, bool *enable, int socket_fd);
bool execution_manage(char *line, builtin_t *toolsbag);

/*== BUILTIN ==*/
void my_list(builtin_t *toolsbag);
void my_send(builtin_t *toolsbag);
void my_clear(builtin_t *toolsbag);
void my_color(builtin_t *toolsbag);
void my_shutdown(builtin_t *toolsbag);

#endif