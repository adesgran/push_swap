/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesgran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 14:00:24 by adesgran          #+#    #+#             */
/*   Updated: 2022/01/08 14:10:52 by adesgran         ###   ########.fr       */
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

int	*fill_tab(int ac, char **av)
{
	int	*tab;

	tab = malloc(sizeof(int) * ac);
	if (!tab)
		return (NULL);
	while (ac)
	{
		tab[ac - 1] = ft_atoi(av[ac - 1]);
		ac--;
	}
	return (tab);
}

int	main(int ac, char **av)
{	
	int	*tab;

	if (ac < 2)
	{
		ft_printf("ERROR : No entry\n");
		return (1);
	}
	tab = fill_tab(ac - 1, av + 1);
	if (!tab)
		return (1);
	ft_printf("Tab : \n");
	print_tab(tab, ac - 1);
	return (0);
}

