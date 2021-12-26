# EXEC
NAME = convert

# DIRS
ODIR = obj
DDIR = dep
SDIR = src
IDIR = includes

# FILES
SRC :=	src/converter/print.cpp \
		src/converter/conversions.cpp \
		src/converter/converter.cpp \
		src/main.cpp \
		src/determine_type/is_double.cpp \
		src/determine_type/is_float.cpp \
		src/determine_type/is_char.cpp \
		src/determine_type/is_int.cpp \
		src/determine_type/determine_type.cpp
OBJ :=	$(patsubst $(SDIR)/%.cpp,$(ODIR)/%.o,$(SRC))
DEP :=	$(patsubst $(SDIR)/%.cpp,$(DDIR)/%.d,$(SRC))

# Settings
CXX = clang++
CXXFLAGS = -Wall -Werror -Wextra -std=c++98 -pedantic
IFLAGS = -I$(IDIR)
RM = rm -f


.PHONY: all
all: $(NAME)

# Rules
$(NAME): $(OBJ)
	$(CXX) -o $@ $(OBJ) $(CXXFLAGS)
$(OBJ): $(ODIR)/%.o: $(SDIR)/%.cpp
	@mkdir -p $(@D)
	$(CXX) $(IFLAGS) -c -o $@ $< $(CXXFLAGS)
$(DEP): $(DDIR)/%.d: $(SDIR)/%.cpp
	@mkdir -p $(@D)
	@$(CC) $< -MM -MF $@ -MT $(ODIR)/$*.o $(IFLAGS)

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
