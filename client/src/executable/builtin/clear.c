/*
** EPITECH PROJECT, 2019
** PROJECT_NAME
** File description:
** DESCRIPTION
*/

#include <stdio.h>

void clear(__attribute__((unused)) char **params)
{
    fprintf(stdout, "\e[1;1H\e[2J");
    fflush(stdout);
}