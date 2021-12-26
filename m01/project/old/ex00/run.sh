SRC='*.cpp'
EXEC='./a.out'
COMP='clang++'
FLAGS='-Wall -Wextra -g -fsanitize=address -std=c++98'

$COMP $SRC $FLAGS -o $EXEC && $EXEC
