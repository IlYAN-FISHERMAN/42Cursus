/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo_repuch_to_a.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 15:14:58 by ilyanar           #+#    #+#             */
/*   Updated: 2023/12/21 18:09:12 by ilyanar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

int	ft_check_pos_a(t_listp **stack, int nb)
{
	t_listp	*tmp;

	tmp = *stack;
	if (nb > ft_max(stack))
		return (ft_max(stack));
	else if (nb < ft_min(stack))
		return (ft_min(stack));
	while (tmp)
	{
		if (tmp->content < nb)
		{
			if (tmp->next)
				if (tmp->next->content > nb)
					return (tmp->next->content);
			if ((*stack)->content > nb && tmp->next == 0)
				return (tmp->content);
		}
		if (((*stack)->content) > nb && ft_lstlast(*stack)->content < nb)
			return ((*stack)->content);
		tmp = tmp->next;
	}
	return (0);
}

void	ft_pa_for_a(t_listp **a, t_listp **b)
{
	if ((*b)->content > ft_max(a))
	{
		ft_pa_pb(a, b, 1);
		ft_ra_rb(a, 1);
	}
	else
		ft_pa_pb(a, b, 1);
}

void	ft_repuch_to_a(t_listp **a, t_listp **b)
{
	int	pos;

	while (*b)
	{
		pos = ft_check_pos_a(a, (*b)->content);
		if (more_or_less(a, pos) == 0 && (*b)->content > ft_max(a))
			while (ft_lstlast(*a)->content != ft_max(a))
				ft_ra_rb(a, 1);
		else if (more_or_less(a, pos) == 1 && (*b)->content > ft_max(a))
			while (ft_lstlast(*a)->content != ft_max(a))
				ft_rra_rrb(a, 1);
		else if (more_or_less(a, pos) == 0 && (*b)->content < ft_min(a))
			while ((*a)->content != ft_min(a))
				ft_ra_rb(a, 1);
		else if (more_or_less(a, pos) == 1 && (*b)->content < ft_min(a))
			while ((*a)->content != ft_min(a))
				ft_ra_rb(a, 1);
		else if (more_or_less(a, pos) == 0)
			while ((*a)->content != pos)
				ft_ra_rb(a, 1);
		else if (more_or_less(a, pos) == 1)
			while ((*a)->content != pos)
				ft_rra_rrb(a, 1);
		ft_pa_for_a(a, b);
	}
}
