/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort5n.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesgran <adesgran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 14:25:04 by adesgran          #+#    #+#             */
/*   Updated: 2022/03/28 15:07:12 by adesgran         ###   ########.fr       */
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
