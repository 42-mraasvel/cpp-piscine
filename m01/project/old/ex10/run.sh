COMP='clang++'
FLAGS='-std=c++98 -Wall -Wextra -Werror'
DFLAGS=' -g -fsanitize=address -fsanitize=leak'
EXEC='./a.out'
SRC='main.cpp'

# FLAGS+=$DFLAGS

$COMP $FLAGS -o $EXEC $SRC && $EXEC $@
