/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesgran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 16:12:57 by adesgran          #+#    #+#             */
/*   Updated: 2022/01/23 17:41:05 by adesgran         ###   ########.fr       */
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
			ft_printf("Loop1\n");
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
			ft_printf("Loop2\n");
		}
	}
	*end = piles->len_a - 1 - (*begin - *end);
	*begin = piles->len_a - 1;
}

static void	merge_parts(t_piles *piles, int size_1, int size_2)
{
	int	i;
	int	j;

	i = 0;
	while (i < size_2 - 1)
	{
		push_b(piles);
		rrotate_a(piles);
		rotate_b(piles);
		i++;
	}
	push_b(piles);
	rotate_b(piles);
	j = 0;
	while (j < size_2 || i)
	{
		if (j == size_2 || (piles->pile_b[i] < piles->pile_a[0] && i))
		{
			push_a(piles);
			i--;
		}
		else
		{
			rrotate_a(piles);
			j++;
		}
	}
}

void	recurs(t_piles *piles, int begin, int end)
{
	ft_printf("Begin : %d End : %d\n", begin, end);
	if (begin - end > 1)
	{
		rotate_to_begin(piles, &begin, &end);

		recurs(piles, begin, (begin + end + 1) / 2);
		rotate_a(piles);
		recurs(piles, begin, (begin + end + 1) / 2 + 1);
	}
	else if (begin - end == 1)
	{
		ft_printf("Diff = 1 : %d\n%d\n", piles->pile_a[begin], piles->pile_a[end]);
		rotate_a(piles);
	}
	else if (begin - end == 0)
		ft_printf("Diff = 0 : %d\n", piles->pile_a[begin]);
}

void	sort2(t_piles *piles)
{
	ft_printf("Start Sort\n");
	recurs(piles, piles->len_a - 1, 0);
}
