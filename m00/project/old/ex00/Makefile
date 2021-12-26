NAME = megaphone

SRC := ./megaphone.cpp
OBJ := $(patsubst %.cpp,%.o,$(SRC))

# Compilation
CPP = clang++
CPPFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	$(CPP) -o $@ $(OBJ) $(CPPFLAGS)

$(OBJ): %.o: %.cpp
	$(CPP) -c -o $@ $< $(CPPFLAGS)

# Clean up
.PHONY: clean fclean re
clean:
	$(RM) $(OBJ)
fclean: clean
	$(RM) $(NAME)
re: fclean
	$(MAKE) all
