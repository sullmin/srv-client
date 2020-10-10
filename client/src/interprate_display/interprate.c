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

static bool set_color(char *balise, bool type)
{
    if (!balise)
        return false;
    for (size_t i = 0; KEY_LINK[i].str[0] && KEY_LINK[i].replace[0]; i++) {
        if (strcmp(balise, KEY_LINK[i].str) == 0) {
            if (KEY_LINK[i].type || !type)
                fprintf(stdout, "%s", KEY_LINK[i].replace);
            free(balise);
            return true;
        }
    }
    free(balise);
    return false;
}

static void distributor_ineract(size_t *u, char *str, size_t *pos_term,
    bool type)
{
    bool current_open = false;
    char *balise = NULL;
    size_t tmp = *u;

    *u += is_match(str + *u, &current_open);
    if (current_open) {
        balise = get_balise(str + *u, u, &current_open);
        *u += (balise) ? strlen(balise) : 0;
        if (set_color(balise, type)) {
            *u -= 1;
            return;
        }
        else
            *u = tmp;
    }
    if (!current_open) {
        fprintf(stdout, "%c", str[*u]);
        *pos_term += 1;
    }
    return;
}

size_t interprate(char *str, bool type)
{
    size_t nb_line = 1;
    struct winsize w;
    size_t pos_term = 0;
    size_t max_size = 0;

    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
    max_size = (type) ? w.ws_col - strlen(START_TAPING) : MAX_LEN;
    for (size_t u = 0; str[u]; u++) {
        distributor_ineract(&u, str, &pos_term, type);
        if (pos_term >= max_size) {
            fprintf(stdout, "\n");
            pos_term = 0;
            max_size += (nb_line == 1) ? strlen(START_TAPING) : 0;
            nb_line++;
        }
    }
    fprintf(stdout, "%s\n", RESET);
    fill_line(w.ws_col);
    fflush(stdout);
    return nb_line;
}