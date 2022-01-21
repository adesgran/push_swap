/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesgran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 13:59:13 by adesgran          #+#    #+#             */
/*   Updated: 2022/01/21 17:58:55 by adesgran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <libft.h>

typedef struct s_piles {
	int	*pile_a;
	int	*pile_b;
	int	len_a;
	int	len_b;
}	t_piles;

int		swap_a(t_piles *piles);
int		swap_b(t_piles *piles);
int		swap_s(t_piles *piles);
int		push_a(t_piles *piles);
int		push_b(t_piles *piles);
int		rotate_a(t_piles *piles);
int		rotate_b(t_piles *piles);
int		rotate_r(t_piles *piles);
int		rrotate_a(t_piles *piles);
int		rrotate_b(t_piles *piles);
int		rrotate_r(t_piles *piles);
t_piles	*init_piles(int ac, char **av);
void	print_piles(t_piles *piles);
int		free_piles(t_piles *piles);
int		pile_is_sort(t_piles *piles);
void	fast_sort(t_piles *piles);
t_piles	*duplicate_piles(t_piles *piles);
#endif
