/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fast_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesgran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 16:55:16 by adesgran          #+#    #+#             */
/*   Updated: 2022/01/21 17:12:30 by adesgran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static void	sort_pile_a(t_piles *piles)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < piles->len_a)
	{
		j = 0;
		while (j < piles->len_a - 1)
		{
			if (piles->pile_a[j] < piles->pile_a[j + 1])
			{
				temp = piles->pile_a[j];
				piles->pile_a[j] = piles->pile_a[j + 1];
				piles->pile_a[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}

static void	split_piles(t_piles *piles)
{
	int	i;
	int	j;

	i = piles->len_a / 2;
	j = 0;
	while (i < piles->len_a)
	{
		piles->pile_b[j] = piles->pile_a[i];
		piles->pile_a[i] = 0;
		i++;
		j++;
	}
	piles->len_b = piles->len_a - piles->len_a / 2;
	piles->len_a = piles->len_a / 2;
}

void	fast_sort(t_piles *piles)
{
	sort_pile_a(piles);
	split_piles(piles);
}
