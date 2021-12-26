COMP='clang++'
FLAGS='-std=c++98 -Wall -Wextra -Werror'
DFLAGS=' -g -fsanitize=address -fsanitize=leak'
EXEC='./a.out'
SRC='*.cpp'

$COMP $FLAGS -o $EXEC $SRC && $EXEC

