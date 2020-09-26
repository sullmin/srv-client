/*
** EPITECH PROJECT, 2019
** PROJECT_NAME
** File description:
** DESCRIPTION
*/

#include "server.h"

static bool send_transmition(client_inf_t *client, size_t offset, msg_t *trans)
{
    int ret = 0;

    fprintf(stdout, "%s\n", (char *) trans->transmition);
    for (size_t u = 0; u < MAX_CLIENT; u++) {
        if (offset != u && client->client_list[u] != 0) {
            ret = write(client->client_list[u], trans, sizeof(msg_t));
            if (ret != -1)
                ret = write(client->client_list[u], trans->transmition, trans->size);
        }
    }
    return (ret != -1) ? true : false;
}

static bool load_trans(msg_t *tr, int fd_actual)
{
    int read_size = 0;
    char *load = (tr->size > 0) ? malloc(sizeof(char) * (tr->size + 1)) : NULL;

    if (!load)
        return false;
    read_size = read(fd_actual, load, tr->size);
    if (read_size > 0) {
        if (tr->type == MSG_TYPE)
            load[read_size] = '\0';
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
            }
            if (!ret)
                return false;
        }
    }
    return true;
}