/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   duplicate_piles.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesgran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 17:37:43 by adesgran          #+#    #+#             */
/*   Updated: 2022/01/21 18:01:34 by adesgran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static void	fill_pile(t_piles *piles, t_piles *res)
{
	int	i;

	res->len_a = piles->len_a;
	res->len_b = piles->len_b;
	i = 0;
	while (i < res->len_a)
	{
		res->pile_a[i] = piles->pile_a[i];
		res->pile_b[i] = piles->pile_b[i];
		i++;
	}
}

t_piles	*duplicate_piles(t_piles *piles)
{
	t_piles	*res;
	int		size;

	res = malloc(sizeof(t_piles));
	if (!res)
		return (res);
	size = piles->len_a + piles->len_b;
	res->pile_a = malloc(sizeof(int) * (size + 1));
	if (!res->pile_a)
	{
		free(res);
		return (NULL);
	}
	res->pile_b = malloc(sizeof(int) * (size + 1));
	if (!res->pile_b)
	{
		free(res->pile_a);
		free(res);
		return (NULL);
	}
	fill_pile(piles, res);
	return (res);
}
