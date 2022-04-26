/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesgran <adesgran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 16:59:07 by adesgran          #+#    #+#             */
/*   Updated: 2022/04/26 16:55:30 by adesgran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static void	rotate_to_begin(t_piles *piles, int size_1)
{
	int	j;

	j = 0;
	if (size_1 / 2 < piles->len_a)
	{
		while (j < size_1 - 1)
		{
			rrotate_a(piles);
			j++;
		}
	}
	else
	{
		while (j < piles->len_a - size_1 + 1)
		{
			rotate_a(piles);
			j++;
		}
	}
}

static int	split_piles(t_piles *piles, int size_1, int size_2, int deep)
{
	int	i;

	i = 0;
	while (i < size_2)
	{
		push_b(piles);
		rrotate_a(piles);
		i++;
	}
	if (deep == 0)
	{
		rotate_a(piles);
		return (i - 1);
	}
	rotate_to_begin(piles, size_1);
	return (i - 1);
}

static void	merge_parts(t_piles *piles, int size_1, int size_2, int deep)
{
	int	i;
	int	j;

	i = split_piles(piles, size_1, size_2, deep);
	j = size_1;
	while (j > 1 || i > -1)
	{
		if (j == 0 || (piles->pile_b[i] < piles->pile_a[piles->len_a - 1] \
					&& i > -1))
		{
			push_a(piles);
			j++;
			if (i > -1)
				i--;
		}
		if (j != 1 || i > -1)
		{
			j--;
			rotate_a(piles);
		}
	}
}

static void	recurs(t_piles *piles, int begin, int end, int deep)
{
	int	size_1;
	int	size_2;

	if (begin - end == 1)
	{
		if (piles->pile_a[begin] > piles->pile_a[end])
			swap_a(piles);
		rotate_a(piles);
		return ;
	}
	else if (begin - end == 2)
		return (sort3n(piles));
	else if (begin - end == 3)
		return (sort4n(piles));
	else if (begin - end == 4)
		return (sort5n(piles));
	else if (begin - end == 5)
		return (sort6n(piles));
	recurs(piles, begin, (begin + end + 1) / 2, deep + 1);
	size_1 = (begin - end + 2) / 2;
	rotate_a(piles);
	size_2 = (begin - end + 1) / 2;
	recurs(piles, begin, begin - size_2 + 1, deep + 1);
	merge_parts(piles, size_1, size_2, deep);
}

void	sort(t_piles *piles)
{
	recurs(piles, piles->len_a - 1, 0, 0);
	if (piles->pile_a[0] < piles->pile_a[piles->len_a - 1])
		rotate_a(piles);
}
