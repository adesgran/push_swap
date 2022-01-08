/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_piles.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesgran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 15:23:45 by adesgran          #+#    #+#             */
/*   Updated: 2022/01/08 15:50:33 by adesgran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static int	*init_pile_a(int ac, char **av)
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

static int	*init_pile_b(int size)
{
	int	*tab;
	int	i;

	tab = malloc(sizeof(int) * size);
	if (!tab)
		return (NULL);
	i = 0;
	while (i < size)
	{
		tab[i] = 0;
		i++;
	}
	return (tab);
}

t_piles	*init_piles(int ac, char **av)
{
	t_piles	*piles;

	piles = malloc(sizeof(t_piles));
	if (!piles)
		return (NULL);
	piles->pile_a = init_pile_a(ac, av);
	if (!piles->pile_a)
	{
		free(piles);
		return (NULL);
	}
	piles->pile_b = init_pile_b(ac);
	if (!piles->pile_a)
	{
		free(piles->pile_a);
		free(piles);
		return (NULL);
	}
	piles->len_a = ac;
	piles->len_b = 0;
	return (piles);
}
