/*
** EPITECH PROJECT, 2019
** client
** File description:
** client
*/

#include "client.h"

int main(int ac, char **av)
{
    user_params_t params = {0};
    struct sockaddr_in my_serv = {0};
    int socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    int ret;

    if (socket_fd <= 0)
        return my_str_error_int("socket_fd ");
    if (!set_user_params(&params, ac, av))
        return EXIT_FAILURE;
    my_serv.sin_family = AF_INET;
    my_serv.sin_port = htons(params.port);
    ret = inet_pton(AF_INET, params.ip, &my_serv.sin_addr);
    if (ret <= 0)
        return my_str_error_int("ip_ret ");
    ret = connect(socket_fd, (struct sockaddr *)&my_serv, sizeof(my_serv));
    if (ret < 0)
        return my_str_error_int("connect_ret ");
    return client_loop(socket_fd);
}