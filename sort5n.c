/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort5n.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesgran <adesgran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 14:25:04 by adesgran          #+#    #+#             */
/*   Updated: 2022/04/26 16:41:51 by adesgran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static int	get_min(int *pile, int init)
{
	int	min;
	int	res;
	int	i;

	min = pile[init];
	res = init;
	i = 1;
	while (i < 5)
	{
		if (pile[init + i] < min)
		{
			min = pile[init + i];
			res = init + i;
		}
		i++;
	}
	return (res);
}

static void	merge_piles(t_piles *piles, int init)
{
	int	len_a;
	int	count;

	len_a = 2;
	count = 0;
	while (piles->len_b)
	{
		if (piles->pile_b[piles->len_b - 1] < piles->pile_a[piles->len_a - 1] \
				|| count == len_a)
		{
			push_a(piles);
			len_a++;
		}
		count++;
		if (count < 5)
			rotate_a(piles);
	}
	while (count < 4)
	{
		count++;
		rotate_a(piles);
	}
}

static void	split_piles_else(t_piles *piles, int *pile, int init)
{
	if (pile[init + 3] < pile[init + 2] && pile[init + 3] < pile[init + 4])
	{
		push_b(piles);
		swap_a(piles);
		push_b(piles);
		if (piles->pile_b[0] < piles->pile_b[1])
			swap_b(piles);
		push_b(piles);
	}
	else
	{
		push_b(piles);
		if (pile[init + 2] > pile[init + 3])
			swap_a(piles);
		push_b(piles);
		push_b(piles);
		if (piles->len_b == 3)
			rrotate_b(piles);
	}
}

static void	split_piles(t_piles *piles, int *pile, int init)
{
	if (pile[init + 2] < pile[init + 3] && pile[init + 2] < pile[init + 4])
	{
		if (pile[init + 3] > pile[init + 4])
			swap_a(piles);
		push_b(piles);
		push_b(piles);
		push_b(piles);
	}
	else
		split_piles_else(piles, pile, init);
	if (piles->pile_a[init] < piles->pile_a[init + 1])
		swap_a(piles);
	merge_piles(piles, init);
}

void	sort5n(t_piles *piles)
{
	int	*pile;
	int	init;

	if (piles->len_a == 5)
		return (sort5nb(piles));
	pile = piles->pile_a;
	init = piles->len_a - 5;
	if (get_min(pile, init) == init + 3)
		swap_a(piles);
	if (get_min(pile, init) == init + 4)
	{
		rotate_a(piles);
		return (sort4n(piles));
	}
	split_piles(piles, pile, init);
}
