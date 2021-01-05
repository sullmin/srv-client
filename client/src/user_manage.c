/*
** EPITECH PROJECT, 2019
** PROJECT_NAME
** File description:
** DESCRIPTION
*/

#include "client.h"

static int get_port_value(char *port)
{
    int port_value = -1;

    if (strisnum(port)) {
        port_value = atoi(port);
    } else {
        printf("%s\n", USER_ERROR_PORT);
    }
    return port_value;
}

bool set_user_params(user_params_t *params, int ac, char **av)
{
    params->port = -1;
    switch (ac) {
        case 3 :
            params->port = get_port_value(av[1]);
            params->ip = av[2];
            break;
        case 1 :
            params->port = get_port_value(PORT);
            params->ip = DEFAULT_IP;
            break;
        default :
            printf("%s\n", USER_ERROR_PARAMS);
            printf("%s%s\n", av[0], USER_ERROR_PARAMS_F);
            printf("%s\n", USER_ERROR_PARAMS_O);
            printf("%s%s\n", av[0], USER_ERROR_PARAMS_S);
    }
    return (params->port == -1) ? false : true;
}