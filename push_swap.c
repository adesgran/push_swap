/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesgran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 14:00:24 by adesgran          #+#    #+#             */
/*   Updated: 2022/04/15 15:48:25 by adesgran         ###   ########.fr       */
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
		ft_printf("ERROR : No entry\n");
		return (1);
	}
	if (checker(ac - 1, av + 1))
	{
		ft_printf("Parsing ERROR\n");
		return (1);
	}
	if (ac == 2)
		piles = init_piles_str(av[1]);
	else
		piles = init_piles(ac - 1, av + 1);
	if (!piles)
		return (1);
//	print_piles(piles);
	sort4(piles);

	//print_piles(piles);
	free_piles(piles);
	return (0);
}
