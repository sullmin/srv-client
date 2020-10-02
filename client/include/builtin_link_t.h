/*
** EPITECH PROJECT, 2019
** client.h
** File description:
** client.h
*/

#ifndef BUILTIN_LINK_T_H
#define BUILTIN_LINK_T_H

#include "builtin_t.h"

typedef struct builtin_link_s
{
    void (*builtin)(builtin_t *toolsbag);
    char name[10];
} builtin_link_t;

#endif