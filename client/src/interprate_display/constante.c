/*
** PERSONAL PROJECT, 2020
** SNAKE
** File description:
** SNAKE
*/

#include "link_t.h"

link_t const KEY_LINK[] = {
    (link_t) {"\e[0m", "Normal", true},
    (link_t) {"\e[1m", "Bold", true},
    (link_t) {"\e[2m", "Dim", true},
    (link_t) {"\e[4m", "Underlined", true},
    (link_t) {"\e[5m", "Blink", true},
    (link_t) {"\e[7m", "inverted", true},
    (link_t) {"\e[8m", "Hidden", true},
    (link_t) {"\e[30m", "Black", true},
    (link_t) {"\e[31m", "Red", true},
    (link_t) {"\e[32m", "Green", true},
    (link_t) {"\e[33m", "Yellow", true},
    (link_t) {"\e[34m", "Blue", true},
    (link_t) {"\e[35m", "Magenta", true},
    (link_t) {"\e[36m", "Cyan", true},
    (link_t) {"\e[37m", "Light gray", true},
    (link_t) {"\e[90m", "Dark gray", true},
    (link_t) {"\e[91m", "Light red", true},
    (link_t) {"\e[92m", "Light green", true},
    (link_t) {"\e[93m", "Light yellow", true},
    (link_t) {"\e[94m", "Light blue", true},
    (link_t) {"\e[95m", "Light magenta", true},
    (link_t) {"\e[96m", "Light cyan", true},
    (link_t) {"\e[97m", "White", true},
    (link_t) {"\e[40m", "SBlack", true},
    (link_t) {"\e[41m", "SRed", true},
    (link_t) {"\e[42m", "SGreen", true},
    (link_t) {"\e[43m", "SYellow", true},
    (link_t) {"\e[44m", "SBlue", true},
    (link_t) {"\e[45m", "SMagenta", true},
    (link_t) {"\e[46m", "SCyan", true},
    (link_t) {"\e[47m", "SLight gray", true},
    (link_t) {"\e[100m", "SDark gray", true},
    (link_t) {"\e[101m", "SLight red", true},
    (link_t) {"\e[102m", "SLight green", true},
    (link_t) {"\e[103m", "SLight yellow", true},
    (link_t) {"\e[104m", "SLight blue", true},
    (link_t) {"\e[105m", "SLight magenta", true},
    (link_t) {"\e[106m", "SLight cyan", true},
    (link_t) {"\e[107m", "SWhite", true},
    (link_t) {"\n", "\\n", false},
    (link_t) {"", "", true},
};