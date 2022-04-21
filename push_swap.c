/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesgran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 14:00:24 by adesgran          #+#    #+#             */
/*   Updated: 2022/04/21 14:27:38 by adesgran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static char	*tab_to_str(int ac, char **av)
{
	char	*res;
	char	*temp;
	int		i;

	temp = ft_strdup(av[0]);
	i = 1;
	while (i < ac)
	{
		res = ft_strjoin(temp, " ");
		if (res == NULL)
			return (NULL);
		free(temp);
		temp = res;
		res = ft_strjoin(temp, av[i]);
		if (res == NULL)
			return (NULL);
		free(temp);
		temp = res;
		i++;
	}
	return (res);
}

static int	checker(int ac, char **av)
{
	char	*str;
	int		res;

	if (ac == 1)
		return (parsing(*av));
	str = tab_to_str(ac, av);
	if (!str)
		return (1);
	res = parsing(str);
	free(str);
	return (res);
}

int	main(int ac, char **av)
{	
	t_piles	*piles;
	t_piles	*copy;

	if (ac < 2)
	{
		ft_printf("Error\n");
		return (1);
	}
	if (checker(ac - 1, av + 1))
	{
		ft_printf("Error\n");
		return (2);
	}
	if (ac == 2)
		piles = init_piles_str(av[1]);
	else
		piles = init_piles(ac - 1, av + 1);
	if (!piles)
		return (1);
	if (n_pile_is_sort(piles, 0, piles->len_a - 1))
		sort(piles);
	free_piles(piles);
	return (0);
}
