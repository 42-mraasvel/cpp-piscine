# EXEC
NAME = a.out

# DIRS
ODIR = obj
DDIR = dep
SDIR = src

# FILES
SRC :=	main.cpp \
		serialize.cpp
OBJ :=	$(patsubst %.cpp,$(ODIR)/%.o,$(SRC))
DEP :=	$(patsubst %.cpp,$(DDIR)/%.d,$(SRC))

# Settings
CXX = clang++
CXXFLAGS = -Wall -Werror -Wextra -std=c++98 -pedantic
RM = rm -f


.PHONY: all
all: $(NAME)

# Rules
$(NAME): $(OBJ)
	$(CXX) -o $@ $(OBJ) $(CXXFLAGS)
$(OBJ): $(ODIR)/%.o: %.cpp
	@mkdir -p $(@D)
	$(CXX) -c -o $@ $< $(CXXFLAGS)
$(DEP): $(DDIR)/%.d: %.cpp
	@mkdir -p $(@D)
	@$(CC) $< -MM -MF $@ -MT $(ODIR)/$*.o

# CLEANUP
.PHONY: clean fclean re
clean:
	$(RM) -r $(ODIR)
	$(RM) -r $(DDIR)
fclean: clean
	$(RM) $(NAME)
re: fclean
	$(MAKE) all

-include $(DEP)
