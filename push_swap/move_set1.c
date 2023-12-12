/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_set1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 19:41:39 by ilyanar           #+#    #+#             */
/*   Updated: 2023/12/12 19:37:32 by ilyanar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

void	ft_sa_sb(t_listp **stacks, int nb)
{
	int	i;

	if (!*stacks || (*stacks)->next == NULL)
		return ;
	i = (*stacks)->content;
	(*stacks)->content = (*stacks)->next->content;
	(*stacks)->next->content = i;
	if (nb == 1)
		ft_printf("sa\n");
	else if (nb == 2)
		ft_printf("sb\n");
}

void	ft_ss(t_listp **a_stack, t_listp **b_stack)
{
	ft_sa_sb(a_stack, 0);
	ft_sa_sb(b_stack, 0);
	ft_printf("ss\n");
}

void	ft_pa_pb(t_listp **stack_recep, t_listp **stack_give, int nb)
{
	t_listp	*tmp;

	if (!*stack_give)
		return ;
	tmp = (*stack_give)->next;
	(*stack_give)->next = 0;
	ft_lstadd_front(stack_recep, *stack_give);
	*stack_give = tmp;
	if (nb == 1)
		ft_printf("pa\n");
	if (nb == 2)
		ft_printf("pb\n");
}

void	ft_ra_rb(t_listp **stack, int check)
{
	t_listp	*tmp;

	if ((*stack)->next == NULL)
		return ;
	ft_lstadd_back(stack, (*stack));
	tmp = (*stack)->next;
	(*stack)->next = 0;
	(*stack) = tmp;
	if (check == 1)
		ft_printf("ra\n");
	if (check == 2)
		ft_printf("rb\n");
}

void	ft_rr(t_listp **a_stack, t_listp **b_stack)
{
	ft_ra_rb(a_stack, 0);
	ft_ra_rb(b_stack, 0);
	ft_printf("rr\n");
}
