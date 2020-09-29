##
## EPITECH PROJECT, 2019
## Makefile doop
## File description:
## task02
##

SRC	=	src/client.c								\
		src/send_msg.c								\
		src/read_serv.c								\
		src/terminal_read.c							\
		src/tools/add_char.c						\
		src/tools/str_error.c						\
		src/tools/canonic.c							\
		src/tools/my_str_to_word_array.c			\
		src/interprate_display/constante.c			\
		src/interprate_display/interprate.c			\

OBJ	=	$(SRC:.c=.o)

NAME	=	run_client

CFLAGS	+=	-Wall	-Wextra -I ./include/ -g

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -o	$(NAME)	$(OBJ) -I ./include/

clean:
	rm	-f 	$(OBJ)

fclean: clean
	rm	-f	$(NAME)

re:	fclean	all