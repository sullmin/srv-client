/*
** EPITECH PROJECT, 2019
** PROJECT_NAME
** File description:
** DESCRIPTION
*/

#include "client.h"

extern const link_t KEY_LINK[];

void my_color(builtin_t *toolsbag)
{
    char *disp = (toolsbag->params) ? toolsbag->params[0] : CODE_DISPLAY;

    for (size_t i = 0; KEY_LINK[i].str[0] && KEY_LINK[i].replace[0]; i++) {
        fprintf(stdout, "%s\"%s\" :\n", CODE_PRES, KEY_LINK[i].str);
        fprintf(stdout, "- %s%s\n", CODE_BEFORE, disp);
        fprintf(stdout,
            "- %s%s%s%s\n\n", CODE_AFTER, KEY_LINK[i].replace, disp, RESET);
        fflush(stdout);
    }
    toolsbag->stat = SUCCESS;
}