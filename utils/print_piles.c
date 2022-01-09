/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_piles.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesgran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 01:36:39 by adesgran          #+#    #+#             */
/*   Updated: 2022/01/09 02:13:22 by adesgran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	print_piles(t_piles *piles)
{
	int	i;
	int	j;

	i = piles->len_a - 1;
	j = piles->len_b - 1;
	if (i > j)
		j = i;
	else
		i = j;
	while (i >= 0 || j >= 0)
	{
		if (i >= 0 && i < piles->len_a)
			ft_printf("%d ", piles->pile_a[i]);
		else
			ft_printf("  ");
		if (j >= 0 && j < piles->len_b)
			ft_printf("%d", piles->pile_b[j]);
		ft_printf("\n");
		i--;
		j--;
	}
	ft_printf("_ _\n");
	ft_printf("a b\n");
	ft_printf("-------------------------------------------------------------------------------------------------\n");
	ft_printf("\n");
}
