NAME = hiBrain
CPP = -c++
CCFLAGS = -Werror -Wall -Wextra -std=c++98
SRC = main.cpp
OBJ = $(SRC:.cpp=.o)

all: $(NAME)
$(NAME): $(OBJ)
	$(CPP) $(CCFLAGS) -o $(NAME) $(OBJ)

%.o: %.cpp
	$(CPP) $(CCFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)
fclean: clean
	rm -f $(NAME)
re: fclean all

.PHONY: all clean fclean re
