ifndef FILES_MK
FILES_MK = 1

# Directories
SDIR := src
ODIR := obj
DDIR := dep
IDIR := includes
LDIR := libs

# Files
SRC :=	src/main.cpp \
		src/phonebook.cpp \
		src/contact.cpp
OBJ := $(patsubst $(SDIR)/%.cpp,$(ODIR)/%.o,$(SRC))
DEP := $(patsubst $(SDIR)/%.cpp,$(DDIR)/%.d,$(SRC))
HDF :=	includes/phonebook.hpp \
		includes/contact.hpp


endif
