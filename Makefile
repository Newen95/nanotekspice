##
## EPITECH PROJECT, 2023
## gogole/20
## File description:
## Makefile
##

NAME 		=	nanotekspice

CPPFLAGS 	=	-std=c++20 -Wall -Wextra -Werror

SOURCES 	=	main.cpp 				\
				src/error_handling.cpp 	\
				src/nanotekspice.cpp

OBJECTS 	=	$(SOURCES:.cpp=.o)

all: 	$(NAME)

$(NAME):	$(OBJECTS)
	g++ $(CPPFLAGS) -o $@ $^

%.o: 	%.cpp
	g++ $(CPPFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all
