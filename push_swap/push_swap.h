/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 12:56:47 by ilyanar           #+#    #+#             */
/*   Updated: 2023/12/18 21:37:45 by ilyanar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct s_listp
{
	int				i;
	int				j;
	int				count;
	int				nb;
	int				nbr;
	int				check;
	int				content;
	struct s_listp	*next;
}	t_listp;

void	ft_sa_sb(t_listp **stacks, int nb);
void	ft_ss(t_listp **a_stack, t_listp **b_stack, int check);
void	print_test(t_listp **a_stack, t_listp **b_stack, int check);
void	ft_pa_pb(t_listp **stack_recep, t_listp **stack_give, int nb);
void	ft_ra_rb(t_listp **stack, int check);
void	ft_rr(t_listp **a_stack, t_listp **b_stack, int check);
void	ft_rra_rrb(t_listp **stack, int check);
void	ft_rrr(t_listp **a_stack, t_listp **b_stack, int check);
void	ft_algo1(t_listp **a_stack, t_listp **b_stack);
void	ft_algo2(t_listp **a, t_listp **b);
void	ft_lstcpy(t_listp **a, t_listp **b, t_listp **a2, t_listp **b2);
void	ft_repuch(t_listp **a, t_listp **b);
void	ft_finish_b(t_listp **b);

int		more_or_less(t_listp **a, int nb);
int		check_rrr(t_listp **b, int nb);
int		ft_check_pos(t_listp **stack, int nb);
int		check_rr(t_listp **b, int nb);
int		the_lowest(t_listp **a, t_listp **b, t_listp **a2, t_listp **b2);
int		ft_clear(t_listp **a_stack, t_listp **b_stack);
int		ft_min(t_listp **stack);
int		ft_max(t_listp **stack);
int		ft_sort_a(t_listp **a_stack, t_listp **b_stack);
int		ft_sort_b1(t_listp **a, t_listp **b, int nb, int check);
int		ft_sort_b2(t_listp **a, t_listp **b, int nb, int check);
int		ft_sort_b3(t_listp **a, t_listp **b, int nb, int check);
int		ft_lstcount(t_listp **stack);

#endif
