##
## EPITECH PROJECT, 2021
## printf
## File description:
## Makefile
##

SRC =	test_name.c	\
		../src/name.c

LIB	=	-L ../ -lmy

HEADER	=	-I ../include

all:
	gcc -o unit_tests $(SRC) $(HEADER) $(LIB) -lcriterion --coverage

run_tests:
	./unit_tests

clean:
	rm -f *.gcno
	rm -f *.gcda
	rm -f *~
	rm -f unit_tests
