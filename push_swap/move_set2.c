/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_set2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 11:35:25 by ilyanar           #+#    #+#             */
/*   Updated: 2023/12/23 08:12:58 by ilyanar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

int	ft_rra_rrb(t_listp **stack, int check)
{
	t_listp	*tmp1;
	t_listp	*tmp2;

	tmp1 = *stack;
	if ((*stack)->next == NULL)
		return (0);
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
	return (1);
}

int	ft_rrr(t_listp **a_stack, t_listp **b_stack, int check)
{
	ft_rra_rrb(a_stack, 0);
	ft_rra_rrb(b_stack, 0);
	if (check == 1)
		ft_printf("rrr\n");
	return (1);
}

int	check_rrr(t_listp **b, int nb)
{
	int	pos;

	pos = ft_check_pos(b, nb);
	if (more_or_less(b, pos) == 1 && ft_max(b) > nb)
	{
		if (ft_lstlast(*b)->content != pos)
			return (1);
	}
	else if (more_or_less(b, pos) == 1 && ft_max(b) < nb)
	{
		if ((*b)->content != pos)
			return (1);
	}
	return (0);
}

int	check_rr(t_listp **b, int nb)
{
	int	pos;

	pos = ft_check_pos(b, nb);
	if (more_or_less(b, pos) == 0 && ft_max(b) > nb)
	{
		if (ft_lstlast(*b)->content != pos)
			return (1);
	}
	else if (more_or_less(b, pos) == 0 && ft_max(b) < nb)
	{
		if ((*b)->content != pos)
			return (1);
	}
	return (0);
}
