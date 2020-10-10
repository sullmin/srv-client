/*
** EPITECH PROJECT, 2019
** PROJECT_NAME
** File description:
** DESCRIPTION
*/

#include <stdio.h>

void delete_line(size_t nb_to_delete)
{
    for (size_t i = 0; i < nb_to_delete; i++) {
        fprintf(stdout, "\33[2K\r");
        if (i != nb_to_delete - 1)
            fprintf(stdout, "\033[A");
        fflush(stdout);
    }
}