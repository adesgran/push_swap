/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piles_swap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesgran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 14:16:23 by adesgran          #+#    #+#             */
/*   Updated: 2022/01/24 18:08:20 by adesgran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	swap_a(t_piles *piles)
{
	ft_printf("sa\n");
	if (piles->len_a < 2)
		return (1);
	ft_swap(&piles->pile_a[piles->len_a - 1], &piles->pile_a[piles->len_a - 2]);
	return (0);
}

int	swap_b(t_piles *piles)
{
	ft_printf("sb\n");
	if (piles->len_b < 2)
		return (1);
	ft_swap(&piles->pile_b[piles->len_b - 1], &piles->pile_b[piles->len_b - 2]);
	return (0);
}

static int	swap_sa(t_piles *piles)
{
	if (piles->len_a < 2)
		return (1);
	ft_swap(&piles->pile_a[piles->len_a - 1], &piles->pile_a[piles->len_a - 2]);
	return (0);
}

static int	swap_sb(t_piles *piles)
{
	if (piles->len_b < 2)
		return (1);
	ft_swap(&piles->pile_b[piles->len_b - 1], &piles->pile_b[piles->len_b - 2]);
	return (0);
}

int	swap_s(t_piles *piles)
{
	int	res;

	ft_printf("ss\n");
	res = 0;
	if (swap_sa(piles))
		res += 1;
	if (swap_sb(piles))
		res += 2;
	return (res);
}
