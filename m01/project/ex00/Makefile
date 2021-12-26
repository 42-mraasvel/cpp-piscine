# Executable
NAME = zombie

# Dirs
ODIR = obj

# Files
SRC :=	main.cpp \
		newZombie.cpp \
		randomChump.cpp \
		Zombie.cpp
OBJ := $(patsubst %.cpp,$(ODIR)/%.o,$(SRC))

# Compilation
CC = clang++
CFLAGS = -Wall -Wextra -Werror -std=c++98
DFLAGS = -O0 -g -fsanitize=address
RM = rm -f

ifdef DEBUG
	CFLAGS += $(DFLAGS)
endif

# Rules
.PHONY: all
all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $@ $(OBJ) $(CFLAGS)
$(OBJ): $(ODIR)/%.o: %.cpp
	@mkdir -p $(@D)
	$(CC) -c -o $@ $< $(CFLAGS)

# Cleanup
.PHONY: clean fclean re
clean:
	$(RM) -r $(ODIR)
fclean: clean
	$(RM) $(NAME)
re: fclean
	$(MAKE) all

.PHONY: debug
debug: fclean
	$(MAKE) all DEBUG=1
