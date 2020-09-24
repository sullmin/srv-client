/*
** EPITECH PROJECT, 2019
** PROJECT_NAME
** File description:
** DESCRIPTION
*/

#include "server.h"

int main(void)
{
    server_inf_t serv = {0};

    if (!init_serv(&serv))
        return EXIT_FAILURE;
    if (!main_while(&serv))
        return EXIT_FAILURE;
    return EXIT_SUCCESS;
}