/*
** EPITECH PROJECT, 2019
** PROJECT_NAME
** File description:
** DESCRIPTION
*/

#include <sys/stat.h>
#include <stdlib.h>

ssize_t get_file_size(int fd)
{
    struct stat file_stat = {0};

    if (fd <= 0)
        return -1;
    if (fstat(fd, &file_stat) == -1)
        return -1;
    return file_stat.st_size;
}