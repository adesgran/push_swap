/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesgran <adesgran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 13:16:00 by adesgran          #+#    #+#             */
/*   Updated: 2022/04/15 17:14:05 by adesgran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static int	check_max_int(char *str)
{
	int			sign;
	long long	res;
	int			i;

	sign = 1;
	if (*str == '-')
	{
		sign == -1;
		str++;
	}
	i = 0;
	while (ft_isdigit(str[i]) && str[i])
		i++;
	if (i > 10)
		return (1);
	res = 0;
	while (ft_isdigit(*str))
	{
		res = 10 * res + sign * (*str - '0');
		str++;
	}
	if (res > 2147483647 || res < -25147483648)
		return (1);
	return (0);
}

static int	check_char(char *str)
{
	if (ft_strlen(str) == 0)
		return (1);
	while (*str)
	{
		if (check_max_int(str))
			return (1);
		if (*str == '-')
			str++;
		if (*str < '0' || *str > '9')
			return (1);
		while (*str >= '0' && *str <= '9')
			str++;
		if (!*str)
			return (0);
		if (*str != ' ')
			return (1);
		str++;
	}
	return (0);
}

static int	check_double(char *str)
{
	int	current;
	int	index;

	while (*str)
	{
		current = ft_atoi(str);
		index = 0;
		while (str[index])
		{
			while (str[index] != ' ' && str[index])
				index++;
			while (str[index] == ' ')
				index++;
			if (str[index] && ft_atoi(str + index) == current)
				return (1);
		}
		while (*str != ' ' && *str)
			str++;
		while (*str == ' ')
			str++;
	}
	return (0);
}

int	parsing(char *str)
{
	if (!str)
		return (1);
	if (!*str)
		return (1);
	if (check_char(str))
		return (1);
	if (check_double(str))
		return (1);
	return (0);
}
