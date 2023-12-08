/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_set1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 19:41:39 by ilyanar           #+#    #+#             */
/*   Updated: 2023/12/08 16:30:08 by ilyanar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

void	ft_sa_sb(t_listp **stacks, int nb)
{
	int	i;

	if (!*stacks)
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

void	ft_pa_pb(t_listp **a_stack, t_listp **b_stack, int nb)
{
	t_listp	*tmp;

	if (nb == 1)
	{
		if (!b_stack)
			return ;
		tmp = (*b_stack)->next;
		(*b_stack)->next = 0;
		ft_lstadd_front(a_stack, *b_stack);
		*b_stack = tmp;
		ft_printf("pa\n");
	}
	else if (nb == 2)
	{
		if (!a_stack)
			return ;
		tmp = (*a_stack)->next;
		(*a_stack)->next = 0;
		ft_lstadd_front(b_stack, *a_stack);
		*a_stack = tmp;
		ft_printf("pb\n");
	}
}

void	ft_ra_rb(t_listp **a_stack, t_listp **b_stack, int check)
{
	if (check == 1)
	{
		if ((*a_stack)->next == NULL)
			return ;
		(ft_lstlast(*a_stack))->next = *a_stack;
		(*a_stack)->next = 0;
		ft_printf("ra\n");
	}
	if (check == 2)
	{
		if ((*b_stack)->next == NULL)
			return ;
		(ft_lstlast(*b_stack))->next = *b_stack;
		(*b_stack)->next = 0;
		ft_printf("rb\n");
	}
}
