##
## EPITECH PROJECT, 2019
## Makefile doop
## File description:
## task02
##

SRC	=	src/main.c								\
		src/matrix/merge_array.c				\
		src/matrix/get_term_matrix.c			\
		src/matrix/display_term_matrix.c		\
		src/tools/destroy.c						\
		src/tools/read_rec.c					\
		src/simulation/simulation.c				\
		src/simulation/external_manage.c		\

OBJ	=	$(SRC:.c=.o)

NAME	=	run_sim

CFLAGS	+=	-Wall	-Wextra	-I./include -g

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -o	$(NAME)	$(OBJ) -I ./include

clean:
	rm	-f 	$(OBJ)

fclean: clean
	rm	-f	$(NAME)

debug: CFLAGS += -g
debug: re

re:	fclean	all
