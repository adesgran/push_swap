for (( i=1;i<=$1;i++ ))
do
	./push_swap `ruby -e "puts (1..$2).to_a.shuffle.join(' ')"` | wc -l
done
