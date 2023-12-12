/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_set2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 13:45:01 by ilyanar           #+#    #+#             */
/*   Updated: 2023/12/12 22:01:45 by ilyanar          ###   ########.fr       */
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

void	ft_algo(t_listp **a_stack, t_listp **b_stack)
{
	(void)b_stack;
	while (*a_stack)
	{
		if ((*a_stack)->next == NULL)
			break ;
		if ((*a_stack)->content > (*a_stack)->next->content)
			ft_sa_sb(a_stack, 1);
		else
			ft_pa_pb(b_stack, a_stack, 2);
	}
}
