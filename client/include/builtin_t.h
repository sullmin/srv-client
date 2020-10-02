/*
** EPITECH PROJECT, 2019
** client.h
** File description:
** client.h
*/

#ifndef BUILTIN_T_H
#define BUILTIN_T_H

#include <stdlib.h>
#include <stdbool.h>

enum status {
    SUCCESS,
    FAILED,
    ECHEC,
    NOTSET
};

typedef struct builtin_s
{
    enum status stat;
    char **params;
    char *to_exec;
    char **parth;
    bool *enable;
    int serv_fd;
} builtin_t;

#endif