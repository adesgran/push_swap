/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piles_reverse_rotate.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesgran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 15:04:14 by adesgran          #+#    #+#             */
/*   Updated: 2022/01/08 15:18:46 by adesgran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	rrotate_a(t_piles *piles)
{
	int	size;

	ft_printf("rra\n");
	if (!piles->len_a)
		return (1);
	size = 1;
	while (size < piles->len_a)
	{
		ft_swap(&piles->pile_a[size], &piles->pile_a[size - 1]);
		size++;
	}
	return (0);
}

int	rrotate_b(t_piles *piles)
{
	int	size;

	ft_printf("rrb\n");
	if (!piles->len_b)
		return (1);
	size = 1;
	while (size < piles->len_b)
	{
		ft_swap(&piles->pile_b[size], &piles->pile_b[size - 1]);
		size++;
	}
	return (0);
}

static int	rrotate_ra(t_piles *piles)
{
	int	size;

	if (!piles->len_a)
		return (1);
	size = 1;
	while (size < piles->len_a)
	{
		ft_swap(&piles->pile_a[size], &piles->pile_a[size - 1]);
		size++;
	}
	return (0);
}

static int	rrotate_rb(t_piles *piles)
{
	int	size;

	if (!piles->len_b)
		return (1);
	size = 1;
	while (size < piles->len_b)
	{
		ft_swap(&piles->pile_b[size], &piles->pile_b[size - 1]);
		size++;
	}
	return (0);
}

int	rrotate_r(t_piles *piles)
{
	int	res;

	ft_printf("rr\n");
	res = 0;
	res += rrotate_ra(piles);
	res += 2 * rrotate_rb(piles);
	return (res);
}
