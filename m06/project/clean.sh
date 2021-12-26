declare folders
folders=( \
	"ex00" \
	"ex01" \
	"ex02" \
)

for i in "${folders[@]}"
do
	make -C $i fclean
done

