/*
** EPITECH PROJECT, 2019
** client.h
** File description:
** client.h
*/

#ifndef MSG_T_H
#define MSG_T_H

#include <stdlib.h>

enum transmission_type {
    MSG_TYPE,
    FILE_TYPE,
    OTHER
};

typedef struct msg_s
{
    enum transmission_type type;
    void *transmission;
    char *extention;
    ssize_t size_ext;
    ssize_t size;
} msg_t;

#endif