NAME = a.out

ODIR = obj

SRC :=	main.cpp
OBJ :=	$(patsubst %.cpp,$(ODIR)/%.o,$(SRC))
HDF :=	Array.hpp

CXX = clang++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic
RM = rm -f

.PHONY: all
all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) -o $@ $(OBJ)
$(OBJ): $(ODIR)/%.o: %.cpp Makefile $(HDF)
	@mkdir -p $(@D)
	$(CXX) -c -o $@ $< $(CXXFLAGS)

# clean
.PHONY: clean fclean re
clean:
	$(RM) -r $(ODIR)
fclean: clean
	$(RM) $(NAME)
re: fclean
	$(MAKE) all
