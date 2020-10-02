/*
** EPITECH PROJECT, 2019
** PROJECT_NAME
** File description:
** DESCRIPTION
*/

#include "client.h"

// static bool select_builtin(char *to_exec, char **params)
// {
//     if (strcmp(to_exec, "clear") == 0) {
//         clear(params);
//         return true;
//     }
//     return false;
// }

// static void isnt_builtin(char *to_exec)
// {
//     fprintf(stdout, "This is not a builtin : %s\n", to_exec);
// }

static bool update_tools(char *once, builtin_t *toolsbag)
{
    toolsbag->to_exec = once;
    toolsbag->params = my_str_to_word_array(once, " \t", true);
    if (!toolsbag->params) {
        toolsbag->stat = FAILED;
        return false;
    }
    return true;
}

bool execution_manage(char *line, builtin_t *toolsbag)
{
    char **mult_exec = my_str_to_word_array(line, ";", false);

    if (!mult_exec)
        return false;
    for (size_t i = 0; mult_exec[i]; i++) {
        if (!update_tools(mult_exec[i], toolsbag))
            return false;
        // if (!exec_manipulate(mult_exec[i]))
        //     return false;
        free_double_tab((void **) toolsbag->params);
    }
    free_double_tab((void **) mult_exec);
    return true;
}