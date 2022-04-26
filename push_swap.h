/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesgran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 13:59:13 by adesgran          #+#    #+#             */
/*   Updated: 2022/04/26 16:09:41 by adesgran         ###   ########.fr       */
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
int		free_piles(t_piles *piles);
int		pile_is_sort(t_piles *piles);
int		n_pile_is_sort(t_piles *piles, int start, int end);
void	sort(t_piles *piles);
t_piles	*init_piles_str(char *str);
void	sort3n(t_piles *piles);
void	sort4n(t_piles *piles);
void	sort5n(t_piles *piles);
void	sort6n(t_piles *piles);
void	sort5nb(t_piles *piles);
int		parsing(char *str);

#endif
