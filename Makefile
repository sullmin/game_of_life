##
## EPITECH PROJECT, 2019
## Makefile doop
## File description:
## task02
##

SRC	=	src/main.c					\

OBJ	=	$(SRC:.c=.o)

NAME	=	run_sim

CFLAGS	+=	-Wall	-Wextra	-I./include

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
