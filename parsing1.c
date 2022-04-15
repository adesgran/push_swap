/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesgran <adesgran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 13:16:00 by adesgran          #+#    #+#             */
/*   Updated: 2022/04/15 13:25:44 by adesgran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static int	check_char(char *str)
{
	while (*str)
	{
		if ((*str >= '0' && *str <= '9') || *str == ' ')
			str++;
		else
			return (1);
	}
	return (0);
}

static int	check_double(char *str)
{
	int	current;
	int	index;

	while (*str)
	{
		if (*str == '0')
			return (1);
		current = ft_atoi(str);
		index = 0;
		while (str[index])
		{
			while (str[index] != ' ' && str[index])
				index++;
			while (str[index] == ' ')
				index++;
			if (ft_atoi(str[index] == current))
				return (1);
		}
		while (*str != ' ' && *str)
			str++;
		while (*str != ' ')
			str++;
	}
	return (0);
}
			
	
int	parsing1(char *str)
{

