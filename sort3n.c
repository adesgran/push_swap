/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort3n.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesgran <adesgran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 12:45:46 by adesgran          #+#    #+#             */
/*   Updated: 2022/04/26 16:33:05 by adesgran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	sort3n_case3(t_piles *piles, int init, int *pile)
{
	push_b(piles);
	if (pile[init] < pile[init + 1])
		swap_a(piles);
	rotate_a(piles);
	rotate_a(piles);
	push_a(piles);
}

void	sort3n_case2(t_piles *piles, int init, int *pile)
{
	if (pile[init + 1] > pile[init] && pile[init + 1] > pile[init + 2])
	{
		if (pile[init + 2] < pile[init])
		{
			rotate_a(piles);
			swap_a(piles);
			rotate_a(piles);
		}
		else
		{
			push_b(piles);
			swap_a(piles);
			rotate_a(piles);
			push_a(piles);
			rotate_a(piles);
		}
	}
	else
		sort3n_case3(piles, init, pile);
}

void	sort3n(t_piles *piles)
{
	int	init;
	int	*pile;

	pile = piles->pile_a;
	init = piles->len_a - 3;
	if (pile[init] > pile[init + 1] && pile[init] > pile[init + 2])
	{
		if (pile[init + 1] < pile[init + 2])
			swap_a(piles);
		if (init != 0)
		{
			rotate_a(piles);
			rotate_a(piles);
		}
	}
	else
		sort3n_case2(piles, init, pile);
}
