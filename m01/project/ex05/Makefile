# Executable
NAME = a.out

# Dirs
ODIR = obj

# Files
SRC :=	main.cpp \
		Karen.cpp
OBJ :=	$(patsubst %.cpp,$(ODIR)/%.o,$(SRC))


# Compilation
CC = clang++
CFLAGS = -Wall -Wextra -Werror -std=c++98

# Other
RM = rm -f

.PHONY: all
all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $(OBJ)
$(OBJ): $(ODIR)/%.o:%.cpp
	@mkdir -p $(@D)
	$(CC) -c $(CFLAGS) -o $@ $<

.PHONY: clean fclean re
clean:
	$(RM) -r $(ODIR)
fclean: clean
	$(RM) $(NAME)
re: fclean
	$(MAKE) all

main.cpp: Karen.hpp
Karen.cpp: Karen.hpp
