##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile
##

SRC	=	src/minishell.c	\
		src/check_path.c	\
		src/istty.c		\
		src/commands.c	\
		src/error_handling.c

OBJ = $(SRC:.c=.o)

NAME = mysh

CFLAGS	+= -Wall -Wextra -W -I include -g

all:	$(NAME)

$(NAME):	$(OBJ)
	make -C lib/my/
	gcc -o $(NAME) $(OBJ) -L lib/my -lmy

clean:
	rm -f $(OBJ)
	rm -f *~
	make clean -C tests

fclean: clean
	make fclean -C lib/my/
	rm -f $(NAME)

re: fclean	all

unit_tests:
	make clean -C tests
	make -C tests

tests_run:
	make run_tests -C tests

.PHONY: clean fclean re
