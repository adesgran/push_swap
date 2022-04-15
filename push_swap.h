/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesgran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 13:59:13 by adesgran          #+#    #+#             */
/*   Updated: 2022/04/15 13:04:11 by adesgran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define SA 11
# define SB 12
# define SS 13
# define PA 14
# define PB 15
# define RA 16
# define RB 17
# define RR 18
# define RRA 19
# define RRB 20
# define RRR 21
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
void	sort1(t_piles *piles);
void	sort2(t_piles *piles);
void	sort3(t_piles *piles);
void	sort4(t_piles *piles);
t_piles	*init_piles_str(char *str);
void	sort3n(t_piles *piles);
void	sort4n(t_piles *piles);
void	sort5n(t_piles *piles);
void	sort5nb(t_piles *piles);
#endif
