/*
** EPITECH PROJECT, 2019
** client.h
** File description:
** client.h
*/

#ifndef BUILTIN_T_H
#define BUILTIN_T_H

#include <stdlib.h>

enum status {
    SUCCESS,
    FAILED,
    ECHEC,
    NOTSET
};

typedef struct builtin_s
{
    enum status stat;
    int serv_fd;
    char **params;
    char *to_exec;
    bool *enable;
} builtin_t;

#endif