# Executable
NAME = a.out

# Dirs
ODIR = obj
DDIR = dep

# Files

SRC :=	main.cpp \
		ClapTrap.cpp \
		ScavTrap.cpp \
		FragTrap.cpp \
		DiamondTrap.cpp
OBJ :=	$(patsubst %.cpp,$(ODIR)/%.o,$(SRC))
DEP :=	$(patsubst %.cpp,$(DDIR)/%.d,$(SRC))

# Settings
CPP = clang++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98 -Wshadow -pedantic
CPPFLAGS = -Wall -Wextra -Werror

RM = rm -f

.PHONY: all
all: $(NAME)

$(NAME): $(OBJ)
	$(CPP) -o $@ $(OBJ) $(CPPFLAGS)
$(OBJ): $(ODIR)/%.o: %.cpp
	@mkdir -p $(@D)
	$(CPP) -c -o $@ $< $(CPPFLAGS)
$(DEP): $(DDIR)/%.d: %.cpp
	@mkdir -p $(@D)
	@$(CPP) $< -MM -MF $@ -MT $(ODIR)/$*.o

.PHONY: clean fclean re
clean:
	$(RM) -r $(ODIR)
	$(RM) -r $(DDIR)
fclean: clean
	$(RM) $(NAME)
re: fclean
	$(MAKE) all

-include $(DEP)
