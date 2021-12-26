declare folders
folders=( "ex00" "ex01" "ex02" "ex03" "ex04" "ex05" "ex06" )

for i in "${folders[@]}"
do
	make -C $i fclean
done

