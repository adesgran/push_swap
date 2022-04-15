/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesgran <adesgran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 14:00:20 by adesgran          #+#    #+#             */
/*   Updated: 2022/04/15 17:23:39 by adesgran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static int	*init_pile_a(int size, int *tab)
{
	int	*res;
	int	i;

	i = 0;
	res = malloc(sizeof(int) * size);
	if (!res)
		return (NULL);
	while (i < size)
	{
		res[size - i - 1] = tab[i];
		i++;
	}
	return (res);
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

static int	count_size(char *str)
{
	int	i;

	 i = 0;
	 while (*str)
	{
		if (*str == '-')
			str++;
		if (ft_isdigit(*str))
			i++;
		while (ft_isdigit(*str))
			str++;
		while ((*str == '-' || ft_isdigit(*str)) == 0 && *str)
		{
			if (*str != ' ')
				return (0);
			str++;
		}
	}
	 return (i);
}

t_piles	*read_str(int size, int *tab)
{
	t_piles	*piles;
	
	piles = malloc(sizeof(t_piles));
	if (!piles)
		return (NULL);
	piles->pile_a = init_pile_a(size, tab);
	if (!piles->pile_a)
	{
		free(piles);
		return (NULL);
	}
	piles->pile_b = init_pile_b(size);
	if (!piles->pile_a)
	{
		free(piles->pile_a);
		free(piles);
		return (NULL);
	}
	piles->len_a = size;
	piles->len_b = 0;
	free(tab);
	return (piles);
}

t_piles	*init_piles_str(char *str)
{
	int	*res;
	int	size;
	int	i;

	size = count_size(str);
	if (size)
		res = malloc(sizeof(int) * size);
	if (!size || !res)
		return (NULL);
	i = 0;
	while (*str)
	{
		res[i] = ft_atoi(str);
		i++;
		if (*str == '-' || *str == '+')
			str++;
		while (ft_isdigit(*str))
			str++;
		while (!(ft_isdigit(*str) || *str == '-') && *str)
			str++;
	}
	return (read_str(size, res));
}
