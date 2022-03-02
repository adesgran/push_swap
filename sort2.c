/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesgran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 16:12:57 by adesgran          #+#    #+#             */
/*   Updated: 2022/03/02 15:09:30 by adesgran         ###   ########.fr       */
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
			DEBUG
			*begin++;
			ft_printf("Loop1\n");
		}
	}
	else
	{
		while (*begin != piles->len_a - 1)
		{
			rrotate_a(piles);
			DEBUG
			*begin--;
			if (*begin < 0)
				*begin = piles->len_a - 1;
			ft_printf("Loop2\n");
		}
	}
	*end = piles->len_a - 1 - (*begin - *end);
	*begin = piles->len_a - 1;
}

static int	split_piles(t_piles *piles, int size_1, int size_2)
{
	int	i;
	int	j;

	ft_printf("SPLIT : Size1=%d Size2=%d\n", size_1, size_2);
	i = 0;
	while (i < size_2)
	{
		push_b(piles);
		DEBUG
		rrotate_a(piles);
		DEBUG
		i++;
	}
	j = 0;
	while (j < size_1 - 1)
	{
		rrotate_a(piles);
		DEBUG
		j++;
	}
	return (i - 1);
}

static void	merge_parts(t_piles *piles, int size_1, int size_2)
{
	int	i;
	int	j;

	ft_printf("MERGE : Size1=%d Size2=%d\n", size_1, size_2);
	i = split_piles(piles, size_1, size_2);
	ft_printf("i = %d\n", i);
	j = size_1;
	while (j > 1 || i > -1)
	{
		if (j == 0 || (piles->pile_b[i] > piles->pile_a[piles->len_a - 1] && i > -1))
		{
			push_a(piles);
			DEBUG
			j++;
			if (i > -1)
				i--;
		}
		if (j != 1 || i > -1)
		{
			j--;
			rotate_a(piles);
			DEBUG
		}
		ft_printf("LOOP\n");
	}
}

void	recurs(t_piles *piles, int begin, int end)
{
	int	size_1;
	int	size_2;

	ft_printf("Recurs Begin=%d End=%d\n", begin, end);
	if (begin - end > 1)
	{
		rotate_to_begin(piles, &begin, &end);
		ft_printf("Recurs 1\n");
		recurs(piles, begin, (begin + end + 1) / 2);
		size_1 = begin - ((begin + end + 1) / 2) + 1;
		rotate_a(piles);
		ft_printf("Recurs 2\n");
		recurs(piles, begin, (begin + end - 1) / 2 + 2);
		size_2 = begin - end - size_1 + 1;
		ft_printf("SIZE1=%d SIZE2=%d\n", size_1, size_2);
		merge_parts(piles, size_1, size_2); 
	}
	else if (begin - end == 1)
	{
		ft_printf("Diff = 1 : %d %d\n", piles->pile_a[begin], piles->pile_a[end]);
		if (piles->pile_a[begin] < piles->pile_a[end])
		{
			swap_a(piles);
			DEBUG
		}
		rotate_a(piles);
		DEBUG
	}
	else if (begin - end == 0)
		ft_printf("Diff = 0 : %d\n", piles->pile_a[begin]);
	else
		ft_printf("ERROR ! ");
}

void	sort2(t_piles *piles)
{
	ft_printf("Start Sort\n");
	recurs(piles, piles->len_a - 1, 0);
}
