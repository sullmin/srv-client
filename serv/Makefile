##
## EPITECH PROJECT, 2019
## Makefile doop
## File description:
## task02
##

SRC	=	src/built_serv.c	\
		src/client_manage.c	\
		src/loop.c			\
		src/tools.c			\
		src/main.c			\
		src/transmition.c	\

OBJ	=	$(SRC:.c=.o)

NAME	=	run_server

CFLAGS	+=	-Wall	-Wextra -I ./include/ -g

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -o	$(NAME)	$(OBJ) -I ./include/

clean:
	rm	-f 	$(OBJ)

fclean: clean
	rm	-f	$(NAME)

re:	fclean	all
