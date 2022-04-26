/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort6n.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesgran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 15:26:53 by adesgran          #+#    #+#             */
/*   Updated: 2022/04/26 17:38:35 by adesgran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static void	merge_piles(t_piles *piles, int init)
{
	int	len_a;
	int	count;

	len_a = 3;
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
		if (count < 6)
			rotate_a(piles);
	}
	while (count < 5)
	{
		count++;
		rotate_a(piles);
	}
}

static void sort_a(t_piles *piles, int *pile, int init)
{
	if (pile[init + 2] > pile[init + 1] && pile[init] < pile[init + 2])
		swap_a(piles);
	if (pile[init + 1] > pile[init] && pile[init + 1] > pile[init + 2])
	{
		rotate_a(piles);
		swap_a(piles);
		rrotate_a(piles);
	}
	if (pile[init + 1] < pile[init + 2])
		swap_a(piles);
}

static void	split_piles_else(t_piles *piles, int *pile, int init)
{
	if (pile[init + 4] < pile[init + 3] && pile[init + 4] < pile[init + 5])
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
		if (pile[init + 3] > pile[init + 4])
			swap_a(piles);
		push_b(piles);
		push_b(piles);
		rrotate_b(piles);
	}
}

static void	split_piles(t_piles *piles, int *pile, int init)
{
	if (pile[init + 3] < pile[init + 4] && pile[init + 3] < pile[init + 5])
	{
		if (pile[init + 4] > pile[init + 5])
			swap_a(piles);
		push_b(piles);
		push_b(piles);
		push_b(piles);
	}
	else
		split_piles_else(piles, pile, init);
	sort_a(piles, pile, init);
	merge_piles(piles, init);
}

void	sort6n(t_piles *piles)
{
	int	*pile;
	int	init;

	pile = piles->pile_a;
	init = piles->len_a - 6;
	split_piles(piles, pile, init);
}
