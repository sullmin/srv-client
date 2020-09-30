/*
** EPITECH PROJECT, 2019
** PROJECT_NAME
** File description:
** DESCRIPTION
*/

#include <stdlib.h>

void free_double_tab(void **tab)
{
    for (size_t i = 0; tab[i]; i++)
        free(tab[i]);
    free(tab);
}