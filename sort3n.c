/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort3n.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesgran <adesgran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 12:45:46 by adesgran          #+#    #+#             */
/*   Updated: 2022/03/30 14:25:03 by adesgran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static void	sequence_1(t_piles *piles)
{
	swap_a(piles);
	rotate_a(piles);
	swap_a(piles);
	rotate_a(piles);
}

static void	sequence_2(t_piles *piles)
{
	push_b(piles);
	push_b(piles);
	rotate_a(piles);
	push_a(piles);
	push_a(piles);
	rotate_a(piles);
}

static void	sequence_3(t_piles *piles)
{
	push_b(piles);
	swap_a(piles);
	rotate_a(piles);
	rotate_a(piles);
	push_a(piles);
}

static void	sequence_4(t_piles *piles)
{
	rotate_a(piles);
	swap_a(piles);
	rotate_a(piles);
}

void	sort3n(t_piles *piles)
{
	int	init;
	int	*pile;

	init = piles->len_a - 3;
	pile = piles->pile_a;
	if (pile[init] < pile[init + 2])
	{
		if (pile[init + 1] < pile[init])
			sequence_1(piles);
		else if(pile[init + 1] > pile[init + 2])
			sequence_2(piles);
		else
			sequence_3(piles);
	}
	else
	{
		if (pile[init + 1] > pile[init])
			sequence_4(piles);
		else
		{
			if (pile[init + 1] < pile[init + 2])
				swap_a(piles);
			rotate_a(piles);
			rotate_a(piles);
		}
	}
}
