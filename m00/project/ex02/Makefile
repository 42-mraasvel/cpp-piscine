# Executable
NAME = a.out

# Dirs
ODIR = obj

# Files
SRC =	Account.cpp \
		tests.cpp
OBJ := $(patsubst %.cpp,$(ODIR)/%.o,$(SRC))

# Compilation
CC = clang++
CFLAGS = -Wall -Wextra -Werror

.PHONY: all
all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $@ $(OBJ) $(CFLAGS)
$(OBJ): $(ODIR)/%.o: %.cpp
	@mkdir -p $(@D)
	$(CC) -c -o $@ $< $(CFLAGS)


.PHONY: clean fclean re
clean:
	rm -rf $(ODIR)
fclean: clean
	rm -f $(NAME)
re: fclean
	$(MAKE) all
