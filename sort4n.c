/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort4n.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesgran <adesgran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 13:13:10 by adesgran          #+#    #+#             */
/*   Updated: 2022/03/28 13:27:07 by adesgran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	get_max(int *pile, int init)
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
