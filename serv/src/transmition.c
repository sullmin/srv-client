/*
** EPITECH PROJECT, 2019
** PROJECT_NAME
** File description:
** DESCRIPTION
*/

#include "server.h"

int my_tram(int fd_to, msg_t *tr)
{
    int ret = write(fd_to, tr, sizeof(msg_t));

    if (ret != -1)
        ret = write(fd_to, tr->transmition, tr->size);
    if (ret != -1 && tr->type == FILE_TYPE)
        ret = write(fd_to, tr->extention, tr->size_ext);
    return ret;
}

static bool send_transmition(client_inf_t *client, size_t offset, msg_t *tr)
{
    int ret = 0;

    if (tr->type == MSG_TYPE)
        fprintf(stdout, "%s\n", (char *) tr->transmition);
    for (size_t u = 0; u < MAX_CLIENT; u++) {
        if (offset != u && client->client_list[u] != 0) {
            ret = my_tram(client->client_list[u], tr);
        }
    }
    return (ret != -1) ? true : false;
}

static bool load_trans(msg_t *tr, int fd_actual)
{
    int read_size = 0;
    char *load = (tr->size > 0) ? malloc(sizeof(char) * (tr->size + 1)) : NULL;
    char *ext = (tr->type == FILE_TYPE) ? malloc(sizeof(char) * (tr->size_ext + 1)) : NULL;

    if (!load)
        return false;
    read_size = read(fd_actual, load, tr->size);
    if (read_size > 0) {
        if (tr->type == MSG_TYPE)
            load[read_size] = '\0';
        else if (tr->type == FILE_TYPE) {
            read(fd_actual, ext, tr->size_ext);
            ext[tr->size_ext] = '\0';
            tr->extention = ext;
            fprintf(stdout, "File transmition of size %li\n", tr->size);
        }
        tr->transmition = (void *) load;
    }
    else {
        free(load);
        return false;
    }
    return true;
}

bool transmition_manage(server_inf_t *serv, client_inf_t *client, fd_set client_update)
{
    msg_t trans = {0};
    bool ret = true;
    int read_size = 0;

    for (size_t i = 0; i < MAX_CLIENT; i++) {
        if (FD_ISSET(client->client_list[i], &client_update)) {
            read_size = read(client->client_list[i], &trans, sizeof(msg_t));
            if (read_size == 0) {
                ret = disconnection_manage(&client->client_list[i], serv);
            }
            else {
                if (!load_trans(&trans, client->client_list[i]))
                    return false;
                ret = send_transmition(client, i, &trans);
                free(trans.transmition);
                free(trans.extention);
            }
            if (!ret)
                return false;
        }
    }
    return true;
}