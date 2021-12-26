# Executable
NAME = a.out

# Dir
ODIR = obj

# Files
SRC :=	main.cpp \
		Fixed.cpp \
		Point.cpp \
		bsp.cpp
OBJ := $(patsubst %.cpp,$(ODIR)/%.o,$(SRC))
HDF :=	Fixed.hpp

# Compilation
CC = clang++
CFLAGS = -Wall -Wextra -Werror -std=c++98

# Other
RM = rm -f

.PHONY: all
all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $(OBJ)
$(OBJ): $(ODIR)/%.o:%.cpp $(HDF)
	@mkdir -p $(@D)
	$(CC) -c $(CFLAGS) -o $@ $<

.PHONY: clean fclean re
clean:
	$(RM) -r $(ODIR)
fclean: clean
	$(RM) $(NAME)
re: fclean
	$(MAKE) all
