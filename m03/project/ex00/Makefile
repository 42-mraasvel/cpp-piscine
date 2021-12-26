# Executable
NAME = a.out

# Dirs
ODIR = obj

# Files

SRC :=	main.cpp \
		ClapTrap.cpp
OBJ :=	$(patsubst %.cpp,$(ODIR)/%.o,$(SRC))
HDF :=	ClapTrap.hpp


# Settings
CPP = clang++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic

RM = rm -f

.PHONY: all
all: $(NAME)

$(NAME): $(OBJ)
	$(CPP) -o $@ $(OBJ) $(CPPFLAGS)
$(OBJ): $(ODIR)/%.o: %.cpp $(HDF)
	@mkdir -p $(@D)
	$(CPP) -c -o $@ $< $(CPPFLAGS)

.PHONY: clean fclean re
clean:
	$(RM) -r $(ODIR)
fclean: clean
	$(RM) $(NAME)
re: fclean
	$(MAKE) all
