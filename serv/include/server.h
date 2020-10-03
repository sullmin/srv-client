/*
** EPITECH PROJECT, 2019
** client.h
** File description:
** client.h
*/

#ifndef SERV_H
#define SERV_H

#include <stdio.h> 
#include <errno.h>
#include <string.h> 
#include <unistd.h> 
#include <stdlib.h> 
#include <stdbool.h> 
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080
#define MAX_CLIENT 5
#define EXIT_ERROR 84
#define EXIT_SUCCESS 0

#define ERROR_SET "Warning FAILED : setsocket"
#define ERROR_SETOPT "Warning FAILED : set option"
#define ERROR_BIND "Warning FAILED : bind"
#define ERROR_LISTEN "Warning FAILED : listen"
#define ERROR_SELECT "Warning FAILED : select"
#define ERROR_ACCEPT "Warning FAILED : accept"
#define ERROR_SEND "Warning FAILED : send"

typedef struct server_inf_s
{
    int socket;
    struct sockaddr_in address;
} server_inf_t;

typedef struct client_inf_s
{
    int client_list[MAX_CLIENT];
    int max_def;
} client_inf_t;

enum transmition_type {
    MSG_TYPE,
    FILE_TYPE,
    OTHER
};

typedef struct msg_s
{
    enum transmition_type type;
    void *transmition;
    char *extention;
    ssize_t size;
} msg_t;

bool init_serv(server_inf_t *serv);
bool main_while(server_inf_t *serv);
bool update_client_list(client_inf_t *client, server_inf_t *serv, fd_set *client_update);
bool new_connection(client_inf_t *client, server_inf_t *serv, fd_set *client_update);
bool my_str_error(const char *str);
bool disconnection_manage(int *client, server_inf_t *serv);
bool transmition_manage(server_inf_t *serv, client_inf_t *client, fd_set client_update);

#endif
