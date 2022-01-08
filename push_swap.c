/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesgran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 14:00:24 by adesgran          #+#    #+#             */
/*   Updated: 2022/01/08 16:02:58 by adesgran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	print_tab(int *tab, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		ft_printf("\t|%d\n", tab[i]);
		i++;
	}
}

void	print_piles(t_piles *piles)
{
	int	i;
	int	j;

	i = piles->len_a - 1;
	j = piles->len_b - 1;
	ft_printf("_____________________\n");
	if (i > j)
		j = i;
	else
		i = j;
	while (i >= 0 || j >= 0)
	{
		if (i >= 0 && i < piles->len_a)
			ft_printf("%d", piles->pile_a[i]);
		ft_printf("\t|  ");
		if (j >= 0 && j < piles->len_b)
			ft_printf("%d", piles->pile_b[j]);
		ft_printf("\n");
		i--;
		j--;
	}
	ft_printf("_____________________\n");
	ft_printf("\n");
}

int	free_piles(t_piles *piles)
{
	free(piles->pile_a);
	free(piles->pile_b);
	free(piles);
	return (1);
}

int	main(int ac, char **av)
{	
	t_piles	*piles;

	if (ac < 2)
	{
		ft_printf("ERROR : No entry\n");
		return (1);
	}
	piles = init_piles(ac - 1, av + 1);
	if (!piles)
		return (1);
	ft_printf("Tab : \n\n");
	print_piles(piles);
	push_b(piles);
	print_piles(piles);
	free_piles(piles);
	return (0);
}

