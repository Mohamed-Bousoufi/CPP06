Name = Conv

SRC =  main.cpp Func.cpp

HEADERS = A.hpp B.hpp C.hpp Base.hpp 

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