/*
** EPITECH PROJECT, 2019
** PROJECT_NAME
** File description:
** DESCRIPTION
*/

#include "server.h"

int main(int ac, char **av)
{
    server_inf_t serv = {0};

    if (!check_user_inf(&serv, ac, av))
        return EXIT_FAILURE;
    if (!init_serv(&serv))
        return EXIT_FAILURE;
    if (!main_while(&serv))
        return EXIT_FAILURE;
    return EXIT_SUCCESS;
}