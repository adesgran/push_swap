/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pile_is_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesgran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 18:13:53 by adesgran          #+#    #+#             */
/*   Updated: 2022/01/14 13:03:48 by adesgran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	pile_is_sort(t_piles *piles)
{
	int	*a;
	int	gap;
	int	i;

	a = piles->pile_a;
	gap = 0;
	i = -1;
	while (++i < piles->len_a)
	{
		if (i)
		{
			if (a[i] < a[i + 1])
				gap += 1;
		}
		else
		{
			if (a[piles->len_a - 1] < a[0])
				gap += 1;
		}
	}
	if (gap == 0 || gap == 1)
		return (-1);
	else if (gap == piles->len_a || gap == piles->len_a - 1)
		return (-1);
	return (0);
}
