NAME = realType
CPP = c++
CCFLAGS = -Werror -Wall -Wextra -std=c++98

INCLUDES = -I include
SRC_D = src
OBJ_D = obj

SRC = $(SRC_D)/main.cpp $(SRC_D)/generate.cpp $(SRC_D)/identify.cpp \
	$(SRC_D)/Base.cpp

OBJ = $(SRC:$(SRC_D)/%.cpp=$(OBJ_D)/%.o)

all: $(NAME)
$(NAME): $(OBJ)
	$(CPP) $(CCFLAGS) $(OBJ) -o $(NAME)

$(OBJ_D)/%.o: $(SRC_D)/%.cpp | $(OBJ_D)
	$(CPP) $(CCFLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_D):
	mkdir -p $(OBJ_D)

clean:
	rm -rf $(OBJ_D)
fclean: clean
	rm -f $(NAME)
re: fclean all

.PHONY: all clean fclean re
