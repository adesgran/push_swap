/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesgran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 14:00:24 by adesgran          #+#    #+#             */
/*   Updated: 2022/01/21 18:00:56 by adesgran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>


int	main(int ac, char **av)
{	
	t_piles	*piles;
	t_piles	*copy;

	if (ac < 2)
	{
		ft_printf("ERROR : No entry\n");
		return (1);
	}
	piles = init_piles(ac - 1, av + 1);
	if (!piles)
		return (1);
	copy = duplicate_piles(piles);
	print_piles(piles);
	sort1(piles);
	free_piles(piles);
	fast_sort(copy);
	ft_printf("\n\nCOPY :\n\n");
	print_piles(copy);
	return (0);
}
