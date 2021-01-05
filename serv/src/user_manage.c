/*
** EPITECH PROJECT, 2019
** PROJECT_NAME
** File description:
** DESCRIPTION
*/

#include "server.h"

static bool set_default_params(server_inf_t *serv, char *port)
{
    bool status = false;

    if (strisnum(port)) {
        serv->port = atoi(port);
        status = true;
    } else {
        printf("%s\n", USER_ERROR_PORT);
        status = false;
    }
    return status;
}

bool check_user_inf(server_inf_t *serv, int ac, char **av)
{
    bool status = false;

    switch (ac) {
        case 2 :
            status = set_default_params(serv, av[1]);
            break;
        case 1 :
            status = set_default_params(serv, DEFAULT_PORT);
            break;
        default :
            printf("%s\n", USER_ERROR_PARAMS);
            printf("%s%s\n", av[0], USER_ERROR_PARAMS_F);
            printf("%s\n", USER_ERROR_PARAMS_O);
            printf("%s%s\n", av[0], USER_ERROR_PARAMS_S);
    }
    return status;
}