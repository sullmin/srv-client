/*
** EPITECH PROJECT, 2019
** client.h
** File description:
** client.h
*/

#ifndef DEFINE_H
#define DEFINE_H

#define MAX_CLIENT 5
#define EXIT_ERROR 84
#define EXIT_SUCCESS 0
#define DEFAULT_PORT "8080"

#define ERROR_SET "Warning FAILED : setsocket"
#define ERROR_SETOPT "Warning FAILED : set option"
#define ERROR_BIND "Warning FAILED : bind"
#define ERROR_LISTEN "Warning FAILED : listen"
#define ERROR_SELECT "Warning FAILED : select"
#define ERROR_ACCEPT "Warning FAILED : accept"
#define ERROR_SEND "Warning FAILED : send"

#define USER_ERROR_PORT "Warning FAILED: Your input is not correct, it's not a port (ex : 8080)"
#define USER_ERROR_PARAMS "Warning FAILED: Your params are not correct"
#define USER_ERROR_PARAMS_F ""
#define USER_ERROR_PARAMS_O " or "
#define USER_ERROR_PARAMS_S " PORT_VALUE"

#endif
