/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pile_is_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesgran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 18:13:53 by adesgran          #+#    #+#             */
/*   Updated: 2022/04/26 16:06:52 by adesgran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	n_pile_is_sort(t_piles *piles, int start, int end)
{
	int	*pile;

	pile = piles->pile_a;
	if (start < end)
	{
		while (start < end)
		{
			if (pile[start] < pile[start + 1])
				return (1);
			start++;
		}
	}
	else if (start > end)
	{
		while (start > end)
		{
			if (pile[start] > pile[start - 1])
				return (1);
			start--;
		}
	}
	return (0);
}

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
