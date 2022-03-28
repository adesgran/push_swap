/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort4n.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesgran <adesgran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 13:13:10 by adesgran          #+#    #+#             */
/*   Updated: 2022/03/28 14:24:29 by adesgran         ###   ########.fr       */
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
	while (i < 4)
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

static void	merge_piles_bis(t_piles *piles, int init)
{
	rotate_a(piles);
	if (piles->pile_a[init + 1] < piles->pile_b[piles->len_b - 1])
	{
		push_a(piles);
		rotate_a(piles);
		if (piles->pile_a[init + 2] < piles->pile_b[piles->len_b - 1])
		{
			push_a(piles);
			rotate_a(piles);
			return ;
		}
		rotate_a(piles);
		push_a(piles);
	}
	else
	{
		rotate_a(piles);
		push_a(piles);
		rotate_a(piles);
		push_a(piles);
	}
}

static void	merge_piles(t_piles *piles, int init)
{
	if (piles->pile_a[init + 1] < piles->pile_b[piles->len_b - 1])
	{
		push_a(piles);
		rotate_a(piles);
		if (piles->pile_a[init + 2] < piles->pile_b[piles->len_b - 1])
		{
			push_a(piles);
			rotate_a(piles);
			rotate_a(piles);
			return ;
		}
		rotate_a(piles);
		if (piles->pile_a[init + 2] < piles->pile_b[piles->len_b - 1])
		{
			push_a(piles);
			rotate_a(piles);
			return ;
		}
		rotate_a(piles);
		push_a(piles);
	}
	else
		merge_piles_bis(piles, init);
}




static void	sort_algo(t_piles *piles, int *pile, int init)
{
	if (pile[init + 2] < pile[init + 3])
		swap_a(piles);
	push_b(piles);
	push_b(piles);
	if (pile[init] > pile[init + 1])
		swap_a(piles);
	merge_piles(piles, init);
}
void	sort4n(t_piles *piles)
{
	int	*pile;
	int init;

	init = piles->len_a - 4;
	pile = piles->pile_a;
	if (get_max == init + 2)
		swap_a(piles);
	if (get_max == init + 3)
	{
		rotate_a(piles);
		return (sort3n(piles));
	}
