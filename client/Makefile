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
		src/tools/canonic.c							\
		src/tools/add_char.c						\
		src/tools/str_error.c						\
		src/tools/my_strcat.c						\
		src/tools/get_time_str.c					\
		src/tools/get_file_size.c					\
		src/tools/free_double_tab.c					\
		src/tools/my_str_to_word_array.c			\
		src/interprate_display/constante.c			\
		src/interprate_display/interprate.c			\
		src/executable/manage_line.c				\
		src/executable/execut.c						\
		src/executable/list_builtin.c				\
		src/executable/builtin/list.c				\
		src/executable/builtin/send.c				\
		src/executable/builtin/clear.c				\
		src/executable/builtin/color.c				\
		src/executable/builtin/shutdown.c			\

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