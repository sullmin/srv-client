/*
** EPITECH PROJECT, 2019
** PROJECT_NAME
** File description:
** DESCRIPTION
*/

#include <stdio.h>
#include "define.h"

void fill_line(size_t len_line)
{
    for (size_t i = 0; i < len_line; i++)
        fprintf(stdout, "%c", END_LINE);
    fprintf(stdout, "\n");
}