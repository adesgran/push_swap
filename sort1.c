
static int	get_min_pos(t_piles *piles)
{
	int	min;
	int	i;
	int	index;

	min = piles->pile_a[0];
	i = 0;
	index = 0;
	while (i < piles->len_a)
	{
		if (piles->pile_a[i] <= min)
		{
			min = piles->pile_a[i];
			index = i;
		}
		i++;
	}
	return (index);
}

static void	rotate_to_min(t_piles *piles)
{
	int	index;
	int	size;
	int	i;

	index = get_min_pos(piles);
	size = piles->len_a;
	if (index >= size / 2)
	{
		i = size - index - 1;
		ft_printf("i = %d\n", i);
		while (i)
		{
			rotate_a(piles);
			print_piles(piles);
			i--;
		}
	}
	else
	{
		i = index + 1;
		while (i)
		{
			rrotate_a(piles);
			print_piles(piles);
			i--;
		}
	}
}

void	sort1(t_piles *piles)
{
	while (piles->len_a)
	{
		rotate_to_min(piles);
		push_b(piles);
		print_piles(piles);
	}
}
