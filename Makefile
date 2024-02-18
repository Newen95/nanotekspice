##
## EPITECH PROJECT, 2023
## gogole/20
## File description:
## Makefile
##

NAME 		=	nanotekspice

SRC_DIR     =   src

OBJ_DIR     =   $(SRC_DIR)/obj

CPPFLAGS 	=	-std=c++20 -Wall -Wextra -Werror

SOURCES 	=	$(wildcard *.cpp) 					\
				$(wildcard $(SRC_DIR)/*.cpp) 		\
				$(wildcard $(SRC_DIR)/component/*.cpp)

OBJECTS 	=	$(patsubst %.cpp,$(OBJ_DIR)/%.o,$(notdir $(SOURCES)))

all: $(NAME)

$(NAME): $(OBJECTS)
	g++ $(CPPFLAGS) -o $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	mkdir -p $(OBJ_DIR)
	g++ $(CPPFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/component/%.cpp
	mkdir -p $(OBJ_DIR)
	g++ $(CPPFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

