NAME=account
CC=c++
SRC=Account.cpp tests.cpp
FLAGS=-Wall -Wextra -Werror
OBJ=$(SRC:.cpp=.o)
ADDFLAGS= -std=c++98

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $@

%.o : %.cpp Account.hpp
	$(CC) $(FLAGS) -c $< -o $@

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all