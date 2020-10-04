/*
** PERSONAL PROJECT, 2020
** SNAKE
** File description:
** SNAKE
*/

#include "client.h"

builtin_link_t const BUILTIN_LIST[] = {
    (builtin_link_t) {my_shutdown, "shutdown"},
    (builtin_link_t) {my_clear, "clear"},
    (builtin_link_t) {my_list, "list"},
    (builtin_link_t) {my_send, "send"},
    (builtin_link_t) {my_color, "color"},
    (builtin_link_t) {0, ""},
};