# Executable
NAME := megaphone


# Directories
SDIR := src
ODIR := obj
DDIR := dep
IDIR := includes
LDIR := libs

# Files
SRC := megaphone.cpp
OBJ := $(patsubst %.cpp,%.o,$(SRC))

# Compilation
CC = clang++
IFLAGS = -I$(IDIR)
LFLAGS =
CFLAGS = -Wall -Wextra -Werror -std=c++98

ifeq ($(shell uname -s),Linux)
	DFLAGS := -O0 -g -fsanitize=address -fsanitize=leak
else
	DFLAGS := -O0 -g -fsanitize=address
endif

ifdef DEBUG
	CFLAGS += $(DFLAGS)
endif

RM = /bin/rm -f

# Rules
.PHONY: all
all:
	$(MAKE) -j4 $(NAME)

# Compilation
$(NAME): $(OBJ)
	$(CC) -o $@ $(OBJ) $(CFLAGS) $(LFLAGS)
$(OBJ): %.o: %.cpp
	$(CC) -c -o $@ $< $(CFLAGS)

# Cleanup
.PHONY: clean fclean re cleanall
clean:
	$(RM) $(OBJ)
fclean: clean
	$(RM) $(NAME)
re: fclean
	$(MAKE) all

# Debug
.PHONY: debug
debug: fclean
	$(MAKE) all DEBUG=1


-include $(DEP)
