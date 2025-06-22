##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## Makefile for rpg project
##

NAME	=	my_rpg

SRC	=	main.c	\
		main_file_intro.c	\
		sprite_intro.c	\
		text_intro.c 	\
		event.c	\

CFLAGS	=	-W -Wall -Wextra -lm

OBJ	=	$(SRC:.c=.o)

CSFML	=	-l csfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio

all:	$(OBJ)
	gcc $(OBJ) -o $(NAME) -I $(CFLAGS) $(CSFML)

clean:
	rm -f $(OBJ) *.c~ *#

fclean: clean
	rm -f $(NAME)

re: fclean all
