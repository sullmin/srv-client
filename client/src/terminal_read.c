/*
** EPITECH PROJECT, 2019
** minishell
** File description:
** minishell
*/

#include "client.h"

static int my_getch(void)
{
    int ret;
    char buf[5] = {0};
    int flags = fcntl(1, F_GETFL, 0);

    if (flags < 0)
        return -1;
    canonical_mode_select(true);
    fcntl(1, F_SETFL, flags | O_NONBLOCK);
    ret = read(0, buf, 4);
    if (ret <= 0)
        return 0;
    canonical_mode_select(false);
    return (int) buf[0];
}

static void display_input(char *line, size_t *last_size)
{
    if (line) {
        delete_line(*last_size + 2);
        fprintf(stdout, "%s", START_TAPING);
        *last_size = interprate(line, true);
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

static bool is_correct_char(const char ch, const char *line)
{
    if (line && strlen(line) > MAX_LEN)
        return false;
    if (ch >= 32 && ch < 127)
        return true;
    return false;
}

char *secondary_loop(int socket_fd, bool *enable)
{
    size_t last_size = 0;
    char *line = NULL;
    int ch = 0;

    while (ch != '\n' && *enable) {
        display_input(line, &last_size);
        ch = my_getch();
        if (ch == 127)
            my_delete_in_line(line);
        else if (is_correct_char(ch, line))
            line = add_char(line, ch);
        serv_read(socket_fd, &last_size, enable);
        usleep(10000);
    }
    fprintf(stdout, "\n");
    return line;
}