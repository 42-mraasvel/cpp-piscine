ifndef SETTINGS_MK
SETTINGS_MK = 1

# Executable
NAME := phonebook

# Compilation
CC = clang++
IFLAGS = -I$(IDIR)
LFLAGS =
CFLAGS = -Wall -Wextra -Werror -std=c++98

	ifeq ($(shell uname -s),Linux)
		DFLAGS := -O0 -g -fsanitize=address -fsanitize=leak
	else
		DFLAGS := -O0 -g -fsanitize=address
	endif

	ifdef DEBUG
		CFLAGS += $(DFLAGS)
	endif

RM = /bin/rm -f

endif
