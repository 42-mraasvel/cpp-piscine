ifndef SETTINGS_MK
SETTINGS_MK = 1

# Compilation
CPP = clang++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98
IFLAGS = -I$(IDIR)

# Other
RM = rm -f

# Debug flags based on OS
	ifeq ($(shell uname),Linux)
		DFLAGS = -O0 -g -fsanitize=address -fsanitize=leak
	else
		DFLAGS = -O0 -g -fsanitize=address
	endif

# Adding debug flags based on define
	ifdef DEBUG
		CPPFLAGS += $(DFLAGS)
	endif

endif
