/*
** EPITECH PROJECT, 2019
** PROJECT_NAME
** File description:
** DESCRIPTION
*/

#include "client.h"

static bool select_builtin(char *to_exec, char **params)
{
    if (strcmp(to_exec, "clear") == 0) {
        clear(params);
        return true;
    }
    return false;
}

static void isnt_builtin(char *to_exec)
{
    fprintf(stdout, "This is not a builtin : %s\n", to_exec);
}

static bool exec_manipulate(char *to_prepare)
{
    char **parth = my_str_to_word_array(to_prepare, " \t", true);
    size_t offset = strlen(STARTEXEC);

    if (!parth)
        return false;
    if (parth[0])
        if (!select_builtin(parth[0] + offset, parth + 1))
            isnt_builtin(parth[0] + offset);
    free_double_tab((void **) parth);
    return true;
}

bool prepare_exec(char *line)
{
    char **mult_exec = my_str_to_word_array(line, ";", false);

    if (!mult_exec)
        return false;
    for (size_t i = 0; mult_exec[i]; i++)
        if (!exec_manipulate(mult_exec[i]))
            return false;
    free_double_tab((void **) mult_exec);
    return true;
}