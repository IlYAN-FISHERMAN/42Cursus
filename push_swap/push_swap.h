/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 12:56:47 by ilyanar           #+#    #+#             */
/*   Updated: 2023/12/28 17:19:39 by ilyanar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct s_listp
{
	int				count;
	int				nb;
	int				nbr;
	int				content;
	struct s_listp	*next;
}	t_listp;

void	beginning_algo(t_listp **a_stack, t_listp **b_stack);
void	check_and_push(t_listp **a, t_listp **b);
void	ft_lstcpy(t_listp **a, t_listp **b, t_listp **a2, t_listp **b2);
void	ft_repuch_to_a(t_listp **a, t_listp **b);
void	ft_pass_atoi(char **av, t_listp **a);
void	ft_sort_finish_a(t_listp **a);
void	print_test(t_listp **a_stack, t_listp **b_stack, int check);

int		ft_sa_sb(t_listp **stacks, int nb);
int		ft_ss(t_listp **a_stack, t_listp **b_stack, int check);
int		ft_pa_pb(t_listp **stack_recep, t_listp **stack_give, int nb);
int		ft_ra_rb(t_listp **stack, int check);
int		ft_rr(t_listp **a_stack, t_listp **b_stack, int check);
int		ft_rra_rrb(t_listp **stack, int check);
int		ft_rrr(t_listp **a_stack, t_listp **b_stack, int check);
int		check_rrr(t_listp **b, int nb);
int		check_rr(t_listp **b, int nb);

int		pre_sort_check(t_listp **a);
int		more_or_less(t_listp **a, int nb);
int		ft_atoi_swap(const char *str, int *check);
int		check_double(t_listp **stack);
int		ft_check_pos(t_listp **stack, int nb);
int		the_lowest(t_listp **a, t_listp **b);
int		ft_clear(t_listp **a_stack, t_listp **b_stack);
int		ft_min(t_listp **stack);
int		ft_max(t_listp **stack);
int		ft_sort_a(t_listp **a_stack, t_listp **b_stack);
int		organize_stacks(t_listp **a, t_listp **b, int nb, int check);
int		sort_a_rrr(t_listp **a, t_listp **b, int nb, int check);
int		organize_b(t_listp **a, t_listp **b, int nb, int check);
int		ft_sort_a(t_listp **a_stack, t_listp **b_stack);
int		more_than3(t_listp **stack);
int		sort_pars(t_listp **a, t_listp **b, char **av, int ac);
int		push_swap(char **av, int ac);

int		count_stack(t_listp **a, t_listp **b, int nb);
int		count_a_rr(t_listp **a, int nb);
int		count_a_rrr(t_listp **a, int nb);
int		count_stack_for_rrr(t_listp **a, t_listp **b, int nb, int pos);
int		count_b_rr(t_listp **b, int nb, int pos);
int		count_b_rrr(t_listp **b, int nb, int pos);

#endif
