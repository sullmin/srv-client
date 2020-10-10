/*
** EPITECH PROJECT, 2019
** PROJECT_NAME
** File description:
** DESCRIPTION
*/

#include <client.h>

static char *get_data_file(int fd, ssize_t size)
{
    char *buf = malloc(sizeof(char) * (size + 1));
    int read_size = 0;

    if (!buf)
        return NULL;
    read_size = read(fd, buf, size);
    if (read_size == -1)
        return NULL;
    return buf;
}

static bool load_file(char *filepath, msg_t *tr)
{
    int fd = 0;

    if (access(filepath, F_OK) == -1)
        return false;
    fd = open(filepath, O_RDONLY);
    if (fd == -1)
        return false;
    tr->size = get_file_size(fd);
    if (tr->size == -1 || tr->size > 80000)
        return false;
    tr->transmission = get_data_file(fd, tr->size);
    if (!tr->transmission)
        return false;
    tr->extention = filepath;
    close(fd);
    return true;
}

static void set_extention(msg_t *load)
{
    ssize_t offset = 0;
    char *str = load->extention;

    for (offset = strlen(str) - 1; offset >= 0 && str[offset] != '/'; offset--);
    load->extention = str + offset + 1;
    load->size_ext = strlen(str + offset + 1);
}

void my_send(builtin_t *toolsbag)
{
    msg_t load = {0};

    load.type = FILE_TYPE;
    if (toolsbag->params && !toolsbag->params[1]) {
        if (!load_file(toolsbag->params[0], &load)) {
            fprintf(stdout, "%s\n", LOADING_FILE_ERROR);
            toolsbag->stat = ECHEC;
            return;
        }
        set_extention(&load);
        if (!send_msg(toolsbag->serv_fd, &load)) {
            toolsbag->stat = FAILED;
            return;
        }
        usleep(100);
        write(toolsbag->serv_fd, load.extention, load.size_ext);
        free(load.transmission);
        toolsbag->stat = SUCCESS;
    }
    else {
        fprintf(stdout, "%s\n", ONLY_ONE_ERROR);
        toolsbag->stat = ECHEC;
    }
}