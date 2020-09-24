/*
** EPITECH PROJECT, 2019
** client
** File description:
** client
*/

#include "client.h"

int main(void)
{
    struct sockaddr_in my_serv = {0};
    int socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    int ret;

    if (socket_fd <= 0)
        my_str_error_int("socket_fd\n");
    my_serv.sin_family = AF_INET; 
    my_serv.sin_port = htons(PORT); 
    ret = inet_pton(AF_INET, "127.0.0.1", &my_serv.sin_addr);
    if (ret <= 0)
        my_str_error_int("ip_ret\n");
    ret = connect(socket_fd, (struct sockaddr *)&my_serv, sizeof(my_serv));
    if (ret < 0)
        my_str_error_int("connect_ret\n");
    return client_loop(socket_fd);
}