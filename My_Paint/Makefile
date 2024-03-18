##
## EPITECH PROJECT, 2023
## MY_PAINT MAKEFILE
## File description:
## Makefile for my_paint project
##

SRCPATH		=	src/

LPATH		=	lib/my

LFLAG		=	-lmy		\
				-lcsfml-graphics	\
				-lcsfml-window		\
				-lcsfml-audio		\
				-lm			\

SRC			=	$(SRCPATH)main.c			\
				$(SRCPATH)paint.c			\
				$(SRCPATH)mainloop.c		\
				$(SRCPATH)get_ressources.c	\
				$(SRCPATH)destroy_ressources.c	\
				$(SRCPATH)drawing.c

OBJ			=	$(SRC:.c=.o)

CFLAGS 		+=	-Wall -Wextra -Iinclude

RM 			=	rm -f

NAME		=	my_paint

all	:	$(NAME)

$(NAME)	:	$(OBJ)
		make -C $(LPATH)
		$(CC) $(CFLAGS) $(OBJ) -o $(NAME) -L$(LPATH) $(LFLAG)

debug: CFLAGS += -g3
debug:	$(OBJ)
		make -C $(LPATH)
		$(CC) $(CFLAGS) $(OBJ) -o $(NAME) -L$(LPATH) $(LFLAG)

test:
		$(CC) $(CFLAGS) test.c -o TEST -L$(LPATH) $(LFLAG) $(LDFLAGS)

clean:
	make clean -C $(LPATH)
	$(RM) $(OBJ)

fclean: clean
	make fclean -C $(LPATH)
	$(RM) *~ *# *.out $(NAME) *.log TEST vgcore*

re:	clean all
