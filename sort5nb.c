/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort5nb.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesgran <adesgran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 12:27:30 by adesgran          #+#    #+#             */
/*   Updated: 2022/04/15 13:10:10 by adesgran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static int	get_mid(int *pile, int init)
{
	int	res;
	int	i;
	int	j;
	int	count;

	res = 0;
	i = 0;
	while (i < 5)
	{
		j = 0;
		count = 0;
		while (j < 5)
		{
			if (pile[j] <= pile[i])
				count++;
			j++;
		}
		if (count == 3)
			return (pile[i]);
		i++;
	}
	return (0);
}

static void	sort_b(t_piles *piles)
{
	int	*pile;

	pile = piles->pile_b;
	if (pile[0] > pile[1] && pile[0] > pile[2])
	{
		if (pile[2] > pile[1])
			swap_b(piles);
	}
	else if (pile[1] > pile[2] && pile[1] > pile[0])
	{
		rrotate_b(piles);
		if (pile[2] > pile[1])
			swap_b(piles);
	}
	else
	{
		rotate_b(piles);
		if (pile[2] > pile[1])
			swap_b(piles);
	}
}

static void	split_pile(t_piles *piles, int init, int mid)
{
	int	i;

	i = piles->len_a - 1;
	while (i >= init && piles->len_b < 3)
	{
		if (piles->pile_a[piles->len_a - 1] >= mid)
			push_b(piles);
		else
			rotate_a(piles);
		i--;
	}
	while (i <= init)
	{
		rrotate_a(piles);
		i++;
	}
	if (piles->pile_a[piles->len_a - 1] < piles->pile_a[piles->len_a - 2])
		swap_a(piles);
	sort_b(piles);
	push_a(piles);
	push_a(piles);
	push_a(piles);
}


void	sort5nb(t_piles *piles)
{
	int	init;
	int *pile;
	int	mid;

	pile = piles->pile_a;
	init = piles->len_a - 5;
	mid = get_mid(pile, init);
	split_pile(piles, init, mid);
}

