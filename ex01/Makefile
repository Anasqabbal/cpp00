NAME=phonebook
CC=c++
ADDFLAGS= -std=c++98
S= -fsanitize=address -g
FLAGS=-Wall -Wextra -Werror $(ADDFLAGS)
SRC= phonebook.cpp main.cpp
OBJ= $(SRC:.cpp=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $@

%.o : %.cpp phonebook.hpp
	$(CC) $(FLAGS) -c $< -o $@

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all