##
## EPITECH PROJECT, 2023
## MY_HUNTER MAKEFILE
## File description:
## Makefile for my_hunter project
##

SRCPATH		=	src/

SRC		=	$(SRCPATH)my_hunter.c				\
			$(SRCPATH)my_hunter_ressources.c	\
			$(SRCPATH)my_hunter_duckmoves.c	\
			$(SRCPATH)my_hunter_death.c		\
			$(SRCPATH)my_hunter_destroy.c		\

OBJ		=	$(SRC:.c=.o)

RM		=	rm

CFLAGS	+=	-Wall -Wextra -iquote include

CC		=	gcc

NAME	=	my_hunter

LIBS	=	-lcsfml-graphics -lcsfml-audio -lcsfml-system

all	:	$(NAME)

$(NAME)	:	$(OBJ)
		$(CC)	$(OBJ) -o $(NAME) $(LIBS)

clean:
	$(RM) -f $(OBJ)

fclean: clean
	$(RM) -f *~ *# *.out $(NAME) *.log

re:	clean all
