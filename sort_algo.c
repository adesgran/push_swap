/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesgran <adesgran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 16:59:07 by adesgran          #+#    #+#             */
/*   Updated: 2022/04/15 16:59:22 by adesgran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static void	rotate_to_begin(t_piles *piles, int *begin, int *end)
{
	if (*begin > piles->len_a / 2)
	{
		while (*begin < piles->len_a - 1)
		{
			rotate_a(piles);
			*begin++;
		}
	}
	else
	{
		while (*begin != piles->len_a - 1)
		{
			rrotate_a(piles);
			*begin--;
			if (*begin < 0)
				*begin = piles->len_a - 1;
		}
	}
	*end = piles->len_a - 1 - (*begin - *end);
	*begin = piles->len_a - 1;
}

static int	split_piles(t_piles *piles, int size_1, int size_2)
{
	int	i;
	int	j;

	i = 0;
	while (i < size_2)
	{
		push_b(piles);
		rrotate_a(piles);
		i++;
	}
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
	return (i - 1);
}

static void	merge_parts(t_piles *piles, int size_1, int size_2)
{
	int	i;
	int	j;

	i = split_piles(piles, size_1, size_2);
	j = size_1;
	while (j > 1 || i > -1)
	{
		if (j == 0 || (piles->pile_b[i] < piles->pile_a[piles->len_a - 1] && i > -1))
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

static void	recurs(t_piles *piles, int begin, int end)
{
	int	size_1;
	int	size_2;

	if (begin - end > 4)
	{
		rotate_to_begin(piles, &begin, &end);
		recurs(piles, begin, (begin + end + 1) / 2);
		size_1 = (begin - end + 2) / 2;
		rotate_a(piles);
		size_2 = (begin - end + 1) / 2;
		recurs(piles, begin, begin - size_2 + 1);
		merge_parts(piles, size_1, size_2); 
	}
	else if (begin - end == 1)
	{
		if (piles->pile_a[begin] > piles->pile_a[end])
			swap_a(piles);
		rotate_a(piles);
	}
	else if (begin - end == 2)
		sort3n(piles);
	else if (begin - end == 3)
		sort4n(piles);
	else if (begin - end == 4)
		sort5nb(piles);
}

void	sort(t_piles *piles)
{
	recurs(piles, piles->len_a - 1, 0);
	if (piles->pile_a[0] < piles->pile_a[piles->len_a - 1])
		rotate_a(piles);
}
