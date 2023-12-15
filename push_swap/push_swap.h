/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 12:56:47 by ilyanar           #+#    #+#             */
/*   Updated: 2023/12/14 19:27:07 by ilyanar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct s_listp
{
	int				i;
	int				nb;
	int				check;
	int				content;
	struct s_listp	*next;
	struct s_listp	*previous;
}	t_listp;

void	ft_sa_sb(t_listp **stacks, int nb);
void	ft_ss(t_listp **a_stack, t_listp **b_stack);
void	print_test(t_listp **a_stack, t_listp **b_stack, int check);
void	ft_pa_pb(t_listp **stack_recep, t_listp **stack_give, int nb);
void	ft_ra_rb(t_listp **stack, int check);
void	ft_rr(t_listp **a_stack, t_listp **b_stack);
void	ft_rra_rrb(t_listp **stack, int check);
void	ft_rrr(t_listp **a_stack, t_listp **b_stack);
void	ft_algo1(t_listp **a_stack, t_listp **b_stack);
t_listp	*more_less(t_listp **a, t_listp **b);

int		ft_clear(t_listp **a_stack, t_listp **b_stack);
int		ft_min(t_listp **stack);
int		ft_max(t_listp **stack);
int		ft_sort_a(t_listp **a_stack, t_listp **b_stack);
int		ft_lstcount(t_listp **stack);

#endif
