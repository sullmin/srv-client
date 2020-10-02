/*
** EPITECH PROJECT, 2019
** PROJECT_NAME
** File description:
** DESCRIPTION
*/

#include "client.h"

extern const builtin_link_t BUILTIN_LIST[];

static void isnt_builtin(builtin_t *toolsbag)
{
    fprintf(stdout, "This is not a builtin : %s\n", toolsbag->to_exec);
    my_list(toolsbag);
}

static void select_builtin(builtin_t *toolsbag)
{
    for (size_t i = 0; BUILTIN_LIST[i].name[0]; ++i) {
        if (strcmp(toolsbag->to_exec, BUILTIN_LIST[i].name) == 0) {
            BUILTIN_LIST[i].builtin(toolsbag);
            break;
        }
    }
    if (toolsbag->stat == NOTSET) {
        toolsbag->stat = ECHEC;
        isnt_builtin(toolsbag);
    }
}

static bool update_tools(char *once, builtin_t *toolsbag)
{
    char **parth = my_str_to_word_array(once, " \t", true);

    if (!parth) {
        toolsbag->stat = FAILED;
        return false;
    }
    toolsbag->parth = parth;
    toolsbag->to_exec = parth[0];
    toolsbag->params = (parth[0]) ? parth + 1 : NULL;
    return true;
}

static bool go_next_exec(builtin_t *toolsbag, char *actual_exec)
{
    if (actual_exec && toolsbag->stat != ECHEC && *(toolsbag->enable))
        return true;
    return false;
}

bool execution_manage(char *line, builtin_t *toolsbag)
{
    char **mult_exec = my_str_to_word_array(line, ";", false);

    if (!mult_exec)
        return false;
    for (size_t i = 0; go_next_exec(toolsbag, mult_exec[i]); i++) {
        if (!update_tools(mult_exec[i], toolsbag))
            return false;
        select_builtin(toolsbag);
        free_double_tab((void **) toolsbag->parth);
    }
    free_double_tab((void **) mult_exec);
    return true;
}