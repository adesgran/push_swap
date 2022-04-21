for (( i=1;i<=$1;i++ ))
do
	./push_swap `ruby -e "puts (0..4).to_a.shuffle.join(' ')"` | wc -l
done
