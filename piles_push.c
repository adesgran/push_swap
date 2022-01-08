/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piles_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesgran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 14:38:38 by adesgran          #+#    #+#             */
/*   Updated: 2022/01/08 15:19:11 by adesgran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	push_a(t_piles *piles)
{
	ft_printf("pa\n");
	if (!piles->len_b)
		return (1);
	ft_swap(&piles->pile_a[piles->len_a], &piles->pile_b[piles->len_b - 1]);
	piles->len_a += 1;
	piles->len_b -= 1;
	return (0);
}

int	push_b(t_piles *piles)
{
	ft_printf("pb\n");
	if (!piles->len_a)
		return (1);
	ft_swap(&piles->pile_b[piles->len_b], &piles->pile_a[piles->len_a - 1]);
	piles->len_b += 1;
	piles->len_a -= 1;
	return (0);
}
