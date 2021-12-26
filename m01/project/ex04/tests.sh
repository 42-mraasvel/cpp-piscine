EXEC='./replace'
ORANGE='\033[0;33m'

start_color() {
	echo -n -e "$ORANGE"
}

end_color() {
	echo -n -e '\033[0m'
}

display_execution() {
	CMD="$1"

	$CMD
	start_color
	echo "Executing: $CMD"
	end_color
	echo
	echo "DIFF"
	diff "$2" "$2"'.replace'
	echo
	echo "END DIFF"
	echo

}

if [[ ! -f "$EXEC" ]]; then
	echo "Please make executable first"
fi

DIR='EXAMPLE_FILES'

F1="$DIR/1.txt"
F2="$DIR/2.txt"
F3="$DIR/3.txt"

display_execution "$EXEC $F1 hello REPLACE" $F1
display_execution "$EXEC $F2 hello hello" $F2
display_execution "$EXEC $F3 blabla W" $F3

