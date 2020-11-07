##
## EPITECH PROJECT, 2019
## Makefile doop
## File description:
## task02
##

SRC	=	src/main.c								\
		src/simulation.c						\
		src/merge_array.c						\
		src/get_term_matrix.c					\
		src/display_term_matrix.c				\
		src/tools/destroy.c						\
		src/tools/read_rec.c					\
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
