# Exec
NAME = a.out

# Dirs
ODIR := obj
DDIR := dep

# Files
SRC :=	main.cpp \
		HumanB.cpp \
		Weapon.cpp \
		HumanA.cpp
OBJ := $(patsubst %.cpp,$(ODIR)/%.o,$(SRC))
DEP := $(patsubst %.cpp,$(DDIR)/%.d,$(SRC))


# Compilation
CC = clang++
CFLAGS = -Wall -Wextra -Werror -std=c++98

# Other
RM = rm -f

.PHONY: all
all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $@ $(OBJ) $(CFLAGS)
$(OBJ): $(ODIR)/%.o: %.cpp
	@mkdir -p $(@D)
	$(CC) -c -o $@ $< $(CFLAGS)
$(DEP): $(DDIR)/%.d: %.cpp
	@mkdir -p $(@D)
	@$(CC) $< -MM -MF $@ -MT $(ODIR)/$*.o

.PHONY: clean fclean re
clean:
	$(RM) -r $(ODIR)
	$(RM) -r $(DDIR)
fclean: clean
	$(RM) $(NAME)
re: fclean
	$(MAKE) all

-include $(DEP)
