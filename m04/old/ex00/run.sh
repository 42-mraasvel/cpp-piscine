CPP='clang++'
FLAGS='-Wall -Wextra -Werror -std=c++98 -pedantic'
EXEC='./a.out'
SRC='*.cpp'


CMD="$CPP $FLAGS -o $EXEC $SRC"
echo "$CMD && $EXEC"
$CMD && $EXEC
