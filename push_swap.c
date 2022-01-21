/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesgran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 14:00:24 by adesgran          #+#    #+#             */
/*   Updated: 2022/01/21 18:00:56 by adesgran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

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

static void	sort_piles(t_piles *piles)
{
	while (piles->len_a)
	{
		rotate_to_min(piles);
		push_b(piles);
		print_piles(piles);
	}
}

int	main(int ac, char **av)
{	
	t_piles	*piles;
	t_piles	*copy;

	if (ac < 2)
	{
		ft_printf("ERROR : No entry\n");
		return (1);
	}
	piles = init_piles(ac - 1, av + 1);
	if (!piles)
		return (1);
	copy = duplicate_piles(piles);
	print_piles(piles);
	sort_piles(piles);
	free_piles(piles);
	fast_sort(copy);
	ft_printf("\n\nCOPY :\n\n");
	print_piles(copy);
	return (0);
}
