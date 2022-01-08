/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesgran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 13:59:13 by adesgran          #+#    #+#             */
/*   Updated: 2022/01/08 14:59:06 by adesgran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <libft.h>

typedef struct	s_piles { 
	int	*pile_a;
	int	*pile_b;
	int	len_a;
	int	len_b;
}	t_piles;

int	swap_a(t_piles *piles)
int	swap_b(t_piles *piles)
int	swap_s(t_piles *piles)
int	push_a(t_piles piles)
int	push_b(t_piles piles)
int	rotate_a(t_piles piles)
int	rotate_b(t_piles piles)
int	rotate_r(t_piles piles)
#endif
