/*
** EPITECH PROJECT, 2019
** define.h
** File description:
** define.h
*/

#ifndef DEFINE_H
#define DEFINE_H

//CLIENT

#define EXIT_ERROR 84
#define PORT "8080"
#define DEFAULT_IP "127.0.0.1"

//INTERPRATE

#define PARTHO "<"
#define PARTHC ">"
#define RESET "\e[0m"
#define START_TAPING "=> "
#define END_LINE '_'
#define MAX_LEN 1400

//EXECUTABLE

#define STARTEXEC "//"

/*== BUILTIN ==*/

#define ONLY_ONE_ERROR "This builtin take only one param"
#define LOADING_FILE_ERROR "Error during the file loading"
#define LOAD_FILE_REPO "./load/"
#define RECEIPT_FILE_MSG "File has been receive at : "
#define CODE_PRES "This is the balise code "
#define CODE_BEFORE "before balise application "
#define CODE_AFTER "after balise application "
#define CODE_DISPLAY "It's a test"
#define DISCONNECTED "You are already disconnected"

#define USER_ERROR_PORT "Warning FAILED: Your input is not correct, it's not a port (ex : 8080)"
#define USER_ERROR_PARAMS "Warning FAILED: Your params are not correct"
#define USER_ERROR_PARAMS_F ""
#define USER_ERROR_PARAMS_O " or "
#define USER_ERROR_PARAMS_S " PORT_VALUE IP_ADDRESS"

#endif