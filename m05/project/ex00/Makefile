NAME = a.out

CXX = clang++
CXXFLAGS = -Wall -Werror -Wextra -std=c++98 -pedantic

ODIR := obj

SRC :=	main.cpp \
		Bureaucrat.cpp
HDF :=	Bureaucrat.hpp
OBJ :=	$(patsubst %.cpp,$(ODIR)/%.o,$(SRC))

RM = rm -f

.PHONY: all
all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) -o $@ $(OBJ) $(CXXFLAGS)
$(OBJ): $(ODIR)/%.o: %.cpp $(HDF)
	@mkdir -p $(@D)
	$(CXX) -c -o $@ $< $(CXXFLAGS)

.PHONY: clean fclean re
clean:
	$(RM) -r $(ODIR)
fclean: clean
	$(RM) $(NAME)
re: fclean
	$(MAKE) all
