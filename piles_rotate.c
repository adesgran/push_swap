/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piles_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesgran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 14:49:02 by adesgran          #+#    #+#             */
/*   Updated: 2022/01/08 14:58:30 by adesgran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	rotate_a(t_piles piles)
{
	int	size;

	ft_printf("ra\n");
	if (!piles->len_a)
		return (1);
	size = piles->len_a + 1;
	while (size)
	{
		ft_swap(&piles->pile_a[size], &piles->pile_a[size - 1]);
		size--;
	}
	return (0);
}

int	rotate_b(t_piles piles)
{
	int	size;

	ft_printf("rb\n");
	if (!piles->len_b)
		return (1);
	size = piles->len_b + 1;
	while (size)
	{
		ft_swap(&piles->pile_b[size], &piles->pile_b[size - 1]);
		size--;
	}
	return (0);
}

static int	rotate_ra(t_piles piles)
{
	int	size;

	if (!piles->len_a)
		return (1);
	size = piles->len_a + 1;
	while (size)
	{
		ft_swap(&piles->pile_a[size], &piles->pile_a[size - 1]);
		size--;
	}
	return (0);
}

static int	rotate_ra(t_piles piles)
{
	int	size;

	if (!piles->len_b)
		return (1);
	size = piles->len_b + 1;
	while (size)
	{
		ft_swap(&piles->pile_b[size], &piles->pile_b[size - 1]);
		size--;
	}
	return (0);
}

int	rotate_r(t_piles piles)
{
	int	res;

	ft_printf("rr\n");
	res = 0;
	res += rotate_ra(piles);
	res += 2 * rotate_rb(piles);
	return (res);
}
