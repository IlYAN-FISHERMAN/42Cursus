/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_set2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 13:45:01 by ilyanar           #+#    #+#             */
/*   Updated: 2023/12/14 01:47:27 by ilyanar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

void	ft_rra_rrb(t_listp **stack, int check)
{
	t_listp	*tmp1;
	t_listp	*tmp2;

	tmp1 = *stack;
	if ((*stack)->next == NULL)
		return ;
	while (tmp1)
	{
		if (tmp1->next->next == NULL)
		{
			tmp2 = tmp1->next;
			tmp1->next = 0;
			ft_lstadd_front(stack, tmp2);
			break ;
		}
		tmp1 = tmp1->next;
	}
	if (check == 1)
		ft_printf("rra\n");
	if (check == 2)
		ft_printf("rrb\n");
}

void	ft_rrr(t_listp **a_stack, t_listp **b_stack)
{
	ft_rra_rrb(a_stack, 0);
	ft_rra_rrb(b_stack, 0);
	ft_printf("rrr\n");
}

void	ft_algo1(t_listp **a_stack, t_listp **b_stack)
{
	if (ft_lstsize(*a_stack) > 3)
		ft_pa_pb(b_stack, a_stack, 2);
	if (ft_lstsize(*a_stack) > 3)
	{
		ft_pa_pb(b_stack, a_stack, 2);
		if ((*b_stack)->content != ft_max(b_stack))
			ft_ra_rb(b_stack, 2);
	}
	while (ft_lstsize(*a_stack) > 3)
	{
		if ((*b_stack)->content != ft_max(b_stack))
			ft_ra_rb(b_stack, 2);
		else if ((*a_stack)->content < ft_lstlast(*b_stack)->content)
		{
			ft_pa_pb(b_stack, a_stack, 2);
			ft_ra_rb(b_stack, 2);
		}
		else if ((*a_stack)->content > ft_max(b_stack))
			ft_pa_pb(b_stack, a_stack, 2);
		else if ((*a_stack)->content > ft_lstlast(*b_stack)->content)
		{
			while ((*a_stack)->content > ft_lstlast(*b_stack)->content)
				ft_rra_rrb(b_stack, 2);
			ft_pa_pb(b_stack, a_stack, 2);
			while ((*b_stack)->content != ft_max(b_stack))
				ft_ra_rb(b_stack, 2);
		}
	}
	ft_algo2(a_stack, b_stack);
}

int	ft_min(t_listp **stack)
{
	t_listp	*tmp;
	int		i;

	tmp = *stack;
	i = tmp->content;
	while (tmp)
	{
		if (tmp->next == NULL)
			return (i);
		if (tmp->content < i)
			i = tmp->content;
		tmp = tmp->next;
	}
	return (i);
}

int	ft_max(t_listp **stack)
{
	t_listp	*tmp;
	int		i;

	tmp = *stack;
	i = tmp->content;
	while (tmp)
	{
		if (tmp->content > i)
			i = tmp->content;
		tmp = tmp->next;
	}
	return (i);
}
