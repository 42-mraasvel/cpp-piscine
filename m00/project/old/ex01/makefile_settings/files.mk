ifndef FILES_MK
FILES_MK = 1

SDIR = src
ODIR = obj
DDIR = dep
IDIR = includes

SRC :=	src/main.cpp \
		src/phonebook.cpp \
		src/contact.cpp

OBJ = $(patsubst $(SDIR)/%.cpp,$(ODIR)/%.o,$(SRC))
DEP = $(patsubst $(SDIR)/%.cpp,$(DDIR)/%.d,$(SRC))

HDF :=	includes/phonebook.hpp \
		includes/contact.hpp

endif
