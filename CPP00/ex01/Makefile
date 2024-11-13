NAME=phonebook
CC=c++
FLAGS= -Wall -Wextra -Werror
ADDFLAGS=-std=c++98
SRC=phonebook.cpp
INCLUDES= phonebook.hpp
OBJ=$(SRC:.cpp=.o)

all : $(NAME)

$(NAEM) : $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $@

%.o : %.cpp
	$(CC) $(FLAGS) -c $< -o $@

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all

.IPHONY : clean