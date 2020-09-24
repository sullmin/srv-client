/*
** PERSONAL PROJECT, 2020
** SNAKE
** File description:
** SNAKE
*/

#include "client.h"

extern const link_t KEY_LINK[];

static bool is_match(char *point, bool *current_open)
{
    static size_t leno = strlen(PARTHO);
    static size_t lenc = strlen(PARTHC);
    bool tmp = *current_open;

    if (strncmp(point, PARTHC, lenc) == 0) {
        *current_open = false;
        if (tmp)
            return lenc;
        else
            return 0;
    } else if (strncmp(point, PARTHO, leno) == 0) {
        *current_open = true;
        return leno;
    }
    return 0;
}

static char *get_balise(char *point, size_t *offset, bool *current_open)
{
    char *ret;
    size_t i = 0;

    for (i = 0; point[i] && *current_open; i++)
        *offset += is_match(point + i, current_open);
    if (*current_open) {
        *current_open = false;
        return NULL;
    }
    ret = strndup(point, i - 1);
    if (!ret)
        exit(EXIT_ERROR);
    return ret;
}

static bool set_color(char *balise)
{
    if (balise) {
        for (size_t i = 0; KEY_LINK[i].str[0] && KEY_LINK[i].replace[0]; i++) {
            if (strcmp(balise, KEY_LINK[i].str) == 0) {
                fprintf(stdout, "%s", KEY_LINK[i].replace);
                free(balise);
                return true;
            }
        }
        free(balise);
    }
    return false;
}

void interprate(char *str)
{
    size_t tmp = 0;
    char *balise = NULL;
    bool current_open = false;

    for (size_t u = 0; str[u]; u++) {
        tmp = u;
        u += is_match(str + u, &current_open);
        if (current_open) {
            balise = get_balise(str + u, &u, &current_open);
            u += (balise) ? strlen(balise) : 0;
            u = (!set_color(balise)) ? tmp : u;
        }
        if (!current_open) {
            fprintf(stdout, "%c", str[u]);
        }
        if (!str[u])
            break;
    }
    fprintf(stdout, "%s", RESET);
    fflush(stdout);
}