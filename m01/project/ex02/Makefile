NAME = a.out

ODIR := obj

SRC := main.cpp
OBJ := $(ODIR)/main.o

CC = clang++
CFLAGS = -Wall -Wextra -Werror -std=c++98

RM = rm -f

.PHONY: all
all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $(OBJ)
$(OBJ): $(ODIR)/%.o:%.cpp
	@mkdir -p $(@D)
	$(CC) -c -o $@ $< $(CFLAGS)

.PHONY: clean fclean re
clean:
	$(RM) -r $(ODIR)
fclean: clean
	$(RM) $(NAME)
re: fclean
	$(MAKE) all
