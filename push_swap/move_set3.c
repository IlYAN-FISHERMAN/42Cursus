/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_set3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 22:01:07 by ilyanar           #+#    #+#             */
/*   Updated: 2023/12/14 02:31:29 by ilyanar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

void	ft_algo2(t_listp **a_stack, t_listp **b_stack)
{
	while (*a_stack)
	{
		if (((*a_stack)->content > (*a_stack)->next->content)
			&& (*a_stack)->content < (*a_stack)->next->next->content)
			ft_sa_sb(a_stack, 1);
		else if (((*a_stack)->content > (*a_stack)->next->content)
			&& (*a_stack)->content > (*a_stack)->next->next->content)
			ft_ra_rb(a_stack, 1);
		else if ((*a_stack)->next->content > (*a_stack)->next->next->content)
			ft_rra_rrb(a_stack, 1);
		else
			break ;
	}
	if (ft_lstsize(*a_stack) == 3 && !*b_stack)
		return ;
	while (*b_stack)
	{
		if ((*a_stack)->content < (*b_stack)->content)
		{
			ft_ra_rb(a_stack, 1);
			if (((*b_stack)->content > (*a_stack)->content)
				&& (*b_stack)->content < ft_lstlast(*a_stack)->content)
				ft_pa_pb(a_stack, b_stack, 1);
			else if ((*b_stack)->content > ft_max(a_stack)
				&& (*a_stack)->content == ft_max(a_stack))
			{
				ft_ra_rb(a_stack, 1);
				ft_pa_pb(a_stack, b_stack, 1);
			}
		}
		else if ((*a_stack)->content > (*b_stack)->content)
		{
			if (((*b_stack)->content < (*a_stack)->content)
				&& (*b_stack)->content < ft_lstlast(*a_stack)->content)
				ft_pa_pb(a_stack, b_stack, 1);
		}
		else
			break ;
	}
	/*while (*b_stack)
	{
		if (((*b_stack)->content < (*a_stack)->content)
			&& (*a_stack)->content < ft_lstlast(*a_stack)->content)
			ft_pa_pb(a_stack, b_stack, 1);
		else if (((*b_stack)->content > (*a_stack)->content)
			&& (*b_stack)->content < ft_lstlast(*a_stack)->content)
		{
			if ((*b_stack)->content > (*a_stack)->content)
				ft_ra_rb(a_stack, 1);
			if ((*b_stack)->content > (*a_stack)->content)
			{
				ft_ra_rb(a_stack, 1);
				ft_pa_pb(a_stack, b_stack, 1);
				ft_rra_rrb(a_stack, 1);
			}
			else
				ft_pa_pb(a_stack, b_stack, 1);
		}
		else if (((*b_stack)->content < (*a_stack)->content)
			&& (*b_stack)->content < ft_lstlast(*a_stack)->content)
		{
			ft_rra_rrb(a_stack, 1);
			ft_pa_pb(a_stack, b_stack, 1);
		}
		else if (((*b_stack)->content > (*a_stack)->content)
			&& (*b_stack)->content > ft_lstlast(*a_stack)->content)
		{
			ft_pa_pb(a_stack, b_stack, 1);
			ft_ra_rb(a_stack, 1);
		}
		else if ((*b_stack)->content < (*a_stack)->content)
			ft_pa_pb(a_stack, b_stack, 1);
		else
			break ;
	}
	*/
}
