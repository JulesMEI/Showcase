##
## EPITECH PROJECT, 2023
## MY_PAINT MAKEFILE
## File description:
## Makefile for my_paint project
##

SRCPATH		=	src/

SRC			=	$(SRCPATH)main.c			\
				$(SRCPATH)strarray_dup.c		\
				$(SRCPATH)get_map.c			\
				$(SRCPATH)game_of_life.c		\
				$(SRCPATH)free_strarray.c		\
				$(SRCPATH)prints.c			\
				$(SRCPATH)transform_cell.c		\
				$(SRCPATH)my_atoi.c			\

OBJ			=	$(SRC:.c=.o)

CFLAGS 		+=	-Wall -Wextra -Iinclude -g -lncurses

NAME		=	gameoflife

all	:	$(NAME)

$(NAME)	:	$(OBJ)
		$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) *.out $(NAME) *.log vgcore*

re:	clean all
