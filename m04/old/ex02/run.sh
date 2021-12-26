CPP='clang++'
FLAGS='-Wall -Wextra -Werror -std=c++98 -pedantic'
EXEC='./a.out'
SRC='*.cpp'


CMD="$CPP $FLAGS -o $EXEC $SRC"

if [[ "$1" = "leaks" ]]; then
	echo "$CMD && valgrind --tool=memcheck $EXEC"
	CMD="$CPP -g3 $FLAGS -o $EXEC $SRC"
	$CMD && valgrind --tool=memcheck $EXEC
else
	echo "$CMD && $EXEC"
	$CMD && $EXEC
fi
