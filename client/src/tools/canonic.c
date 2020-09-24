/*
** EPITECH PROJECT, 2019
** PROJECT_NAME
** File description:
** DESCRIPTION
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