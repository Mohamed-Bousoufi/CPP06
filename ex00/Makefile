Name = Convert

SRC = ScalarConverter.cpp main.cpp

HEADERS = ScalarConverter.hpp

CC = c++ -Wall -Wextra -Werror -Wshadow -std=c++98 

OBJ = $(SRC:.cpp=.o)

all: $(Name)

$(Name): $(OBJ)
	$(CC) $(OBJ) -o $(Name)

%.o: %.cpp $(HEADERS)
	$(CC) -c $< -o $@


clean: 
	rm -rf $(OBJ)
fclean: clean
	rm -rf $(Name)

re: fclean all

.PHONY: all clean fclean re