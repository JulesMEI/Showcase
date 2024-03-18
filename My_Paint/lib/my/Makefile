##
## EPITECH PROJECT, 2023
## Makefile for day 10
## File description:
## Makefile for the my_printf project
##

SRC	=	mini_printf_dependencies.c		\
		error_mini_printf.c				\
		mini_printf.c					\
		my_strlen.c						\
		my_strcopy.c					\
		my_strcompare.c					\
		my_split.c						\
		my_strfuse.c					\
		my_atoi.c

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

RM	=	rm -f

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)
	cp $(NAME) ../

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) *~ *# *.out
	$(RM) $(NAME) ../$(NAME)

re:	fclean all
