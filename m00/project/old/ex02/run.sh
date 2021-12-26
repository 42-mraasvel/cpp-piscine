COMP='clang++'
FLAGS='-std=c++98 -Wall -Wextra -Werror -g -fsanitize=address'
SRC='*.cpp'
EXEC='./a.out'


$COMP $FLAGS $SRC -o $EXEC && $EXEC
