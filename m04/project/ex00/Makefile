# Exec
NAME = a.out

# Dirs
ODIR = obj
DDIR = dep

# Files
SRC =	main.cpp \
		Animal.cpp \
		Dog.cpp \
		Cat.cpp \
		WrongAnimal.cpp \
		WrongCat.cpp

OBJ =	$(patsubst %.cpp,$(ODIR)/%.o,$(SRC))
DEP =	$(patsubst %.cpp,$(DDIR)/%.d,$(SRC))

# Settings
CXX = clang++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic

RM = rm -f

# Rules
.PHONY: all
all: $(NAME)

# Compilation
$(NAME): $(OBJ)
	$(CXX) $(OBJ) -o $@
$(OBJ): $(ODIR)/%.o: %.cpp
	@mkdir -p $(@D)
	$(CXX) -c -o $@ $< $(CXXFLAGS)
$(DEP): $(DDIR)/%.d: %.cpp
	@mkdir -p $(@D)
	@$(CXX) $< -MM -MF $@ -MT $(ODIR)/$*.o

# Clean up
.PHONY: clean fclean re
clean:
	$(RM) -r $(ODIR)
	$(RM) -r $(DDIR)
fclean: clean
	$(RM) $(NAME)
re: fclean
	$(MAKE) all

-include $(DEP)
