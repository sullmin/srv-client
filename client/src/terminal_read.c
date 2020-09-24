/*
** EPITECH PROJECT, 2019
** minishell
** File description:
** minishell
*/

#include "client.h"

void canonical_mode_select(bool enable)
{
    static struct termios old;
    static struct termios new;

    if (enable) {
        ioctl(0, TCGETS, &old);
        ioctl(0, TCGETS, &new);

        new.c_lflag &= ~ECHO;
        new.c_lflag &= ~ICANON;
        ioctl(0, TCSETS, &new);
    }
    else if (!enable) {
        ioctl(0, TCSETS, &old);
    }
}

static int my_getch(void)
{
    int ret;
    char buf[5] = {0};
    int flags = fcntl(1, F_GETFL, 0);

    fcntl(1, F_SETFL, flags | O_NONBLOCK);
    canonical_mode_select(true);
    ret = read(0, buf, 4);
    if (ret <= 0)
        return 0;
    canonical_mode_select(false);
    return (int) buf[0];
}

static void display_input(char *line)
{
    if (line) {
        fprintf(stdout, "%sYOU: ", "\33[2K\r");
        interprate(line);
        fflush(stdout);
    }
}

static void my_delete_in_line(char *line)
{
    int len = 0;

    if (line) {
        len = strlen(line) - 1;
        len = (len < 0) ? 0 : len;
        line[len] = '\0';
    }
}

char *terminal_read(int socket_fd)
{
    char *line = NULL;
    int ch = 0;

    while (ch != '\n') {
        display_input(line);
        ch = my_getch();
        if (ch == 127)
            my_delete_in_line(line);
        else if (ch != 0 && ch != '\n')
            line = add_char(line, ch);
        serv_read(socket_fd);
    }
    fprintf(stdout, "\n");
    return line;
}