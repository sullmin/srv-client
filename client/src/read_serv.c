/*
** EPITECH PROJECT, 2019
** PROJECT_NAME
** File description:
** DESCRIPTION
*/

#include "client.h"

static bool file_receipt(msg_t *tr)
{
    char *filepath = str_dup_cat(2, LOAD_FILE_REPO, tr->extention);
    int fd = 0;

    if (!filepath)
        return false;
    if (access(filepath, F_OK) != -1)
        return false;
    fd = open(filepath, O_WRONLY | O_CREAT | O_APPEND, 0664);
    if (fd == -1)
        return false;
    write(fd, (char *) tr->transmission, tr->size);
    fprintf(stdout, "%s%s\n", RECEIPT_FILE_MSG, filepath);
    free(filepath);
    close(fd);
    return true;
}

static void msg_receipt(char *load, int read_size)
{
    load[read_size] = '\0';
    fprintf(stdout, "\33[2K\r");
    interprate(load);
    fprintf(stdout, "\n");
}

static bool file_manage(msg_t *tr, char *load, int socket_fd)
{
    int read_size = 0;

    tr->extention = malloc(sizeof(char) * (tr->size_ext + 1));
    if (!tr->extention)
        return false;
    read_size = read(socket_fd, tr->extention, tr->size_ext);
    if (read_size < 0)
        return false;
    tr->extention[tr->size_ext] = '\0';
    tr->transmission = load;
    if (!file_receipt(tr))
        return false;
    free(tr->extention);
    return true;
}

static bool manage_receipt(int socket_fd, msg_t *tr)
{
    int read_size = 0;
    char *load = (tr->size > 0) ? malloc(sizeof(char) * (tr->size + 1)) : NULL;

    if (!load)
        return false;
    usleep(100);
    read_size = read(socket_fd, load, tr->size);
    if (read_size > 0) {
        if (tr->type == MSG_TYPE) {
            msg_receipt(load, read_size);
        }
        else if (tr->type == FILE_TYPE){
            if (!file_manage(tr, load, socket_fd))
                return false;
        }
    }
    free(load);
    return true;
}

void serv_read(int socket_fd)
{
    msg_t receipt = {0};
    int read_size;
    int flags = fcntl(socket_fd, F_GETFL, 0);

    canonical_mode_select(true);
    fcntl(socket_fd, F_SETFL, flags | O_NONBLOCK);
    read_size = read(socket_fd, &receipt, sizeof(msg_t));
    if (read_size > 0) {
        manage_receipt(socket_fd, &receipt);
    }
    canonical_mode_select(false);
}