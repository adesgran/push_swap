/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_piles.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesgran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 01:36:39 by adesgran          #+#    #+#             */
/*   Updated: 2022/01/24 18:31:57 by adesgran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	print_piles(t_piles *piles)
{
	static int	count;
	int	i;
	int	j;

	if (!count)
		count = 0;
	count++;
//	if (count > 10)
//		exit(1);
	i = piles->len_a - 1;
	j = piles->len_b - 1;
	if (i > j)
		j = i;
	else
		i = j;
	ft_printf("--\n");
	while (i >= 0 || j >= 0)
	{
		ft_printf("%d |\t", i);
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
	ft_printf("--\n");
	ft_printf("\t_ _\n");
	ft_printf("\ta b\n");
	ft_printf("--------------\n");
	ft_printf("\n");
}
