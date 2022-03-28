/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort5n.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesgran <adesgran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 14:25:04 by adesgran          #+#    #+#             */
/*   Updated: 2022/03/28 15:23:55 by adesgran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static int	get_max(int *pile, int init)
{
	int	max;
	int	res;
	int	i;

	max = pile[init];
	res = init;
	i = 1;
	while (i < 5)
	{
		if (pile[init + i] > max)
		{
			max = pile[init + i];
			res = init + i;
		}
		i++;
	}
	return (res);
}

static	split_piles(t_piles *piles, int *pile, int init)
{
	if (pile[init + 2] > pile[init + 3] && pile[init + 2] > pile[init + 4])
	{
		if (pile[init + 3] < pile[init + 4])
			swap_a(piles);
		push_b(piles);
		push_b(piles);
		push_b(piles);
	}
	else if (pile[init + 3] > pile[init + 2] && pile[init + 3] > pile[init + 4])
	{
		push_b(piles);
		swap_a(piles);
		push_b(piles);
		if (piles->pile_b[piles->len_b - 1] > piles->pile_b[piles->len_b - 2])
			swap_b(piles);
		push_b(piles);
	}
	else
	{
		push_b(piles);
		if (piles->len_b == 1)
			rotate_b(piles);
		if (pile[init + 2] < pile[init + 3])
			swap_a(piles);
		push_b(piles);
		push_b(piles);
		if (piles->len_b == 3)
			rrotate_b(piles);
	}
	if (pile[init] > pile[init + 1])
		swap_a(piles);
}

void	sort5n(t_piles *piles)
{
	int	*pile;
	int	init;

	pile = piles->pile_a;
	init = piles->len_a - 5;
	if (get_max(pile, init) == init + 3)
		swap_a(piles);
	if (get_max(pile, init) == init + 4)
		return (sort4n(piles));
}
