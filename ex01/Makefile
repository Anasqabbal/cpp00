NAME=Phonebook
CC=c++
ADDFLAGS= -std=c++98
S= -fsanitize=address -g
FLAGS=-Wall -Wextra -Werror $(ADDFLAGS)
SRC= Phonebook.cpp main.cpp Contact.cpp 
OBJ= $(SRC:.cpp=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $@

%.o : %.cpp Phonebook.hpp Contact.hpp
	$(CC) $(FLAGS) -c $< -o $@

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all