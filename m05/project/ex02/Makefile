NAME = a.out

CXX = clang++
CXXFLAGS = -Wall -Werror -Wextra -std=c++98 -pedantic

ODIR := obj
DDIR := dep

SRC :=	main.cpp \
		Bureaucrat.cpp \
		Form.cpp \
		PresidentialPardonForm.cpp \
		RobotomyRequestForm.cpp \
		ShrubberyCreationForm.cpp
OBJ :=	$(patsubst %.cpp,$(ODIR)/%.o,$(SRC))
DEP :=	$(patsubst %.cpp,$(DDIR)/%.d,$(SRC))

RM = rm -f

.PHONY: all
all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) -o $@ $(OBJ) $(CXXFLAGS)
$(OBJ): $(ODIR)/%.o: %.cpp
	@mkdir -p $(@D)
	$(CXX) -c -o $@ $< $(CXXFLAGS)
$(DEP): $(DDIR)/%.d: %.cpp
	@mkdir -p $(@D)
	@$(CXX) $< -MM -MF $@ -MT $(ODIR)/$*.o $(IFLAGS)

.PHONY: clean fclean re
clean:
	$(RM) -r $(ODIR)
	$(RM) -r $(DDIR)
fclean: clean
	$(RM) $(NAME)
re: fclean
	$(MAKE) all

-include $(DEP)
