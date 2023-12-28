/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 11:35:07 by ilyanar           #+#    #+#             */
/*   Updated: 2023/12/28 17:19:25 by ilyanar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

void	beginning_algo(t_listp **a, t_listp **b)
{
	if (more_than3(a) == 1)
		ft_pa_pb(b, a, 2);
	if (more_than3(a) == 1)
		ft_pa_pb(b, a, 2);
	if (more_than3(a) == 1)
		check_and_push(a, b);
	if (more_than3(a) == 0)
		ft_sort_a(a, b);
	if (*b)
		ft_repuch_to_a(a, b);
	ft_sort_finish_a(a);
}

void	check_and_push(t_listp **a, t_listp **b)
{
	int		nb;

	while (more_than3(a) != 0)
	{
		nb = the_lowest(a, b);
		organize_stacks(a, b, nb, 1);
	}
}

void	ft_sort_finish_a(t_listp **a)
{
	int	max;

	max = ft_max(a);
	if (more_or_less(a, max) == 0)
	{
		while ((ft_lstlast(*a)->content) != max)
			ft_ra_rb(a, 1);
	}
	else
	{
		while ((ft_lstlast(*a)->content) != max)
			ft_rra_rrb(a, 1);
	}
}

int	count_stack(t_listp **a, t_listp **b, int nb)
{
	int		count_a;
	int		count_b;
	int		pos;

	pos = ft_check_pos(b, nb);
	if (more_or_less(a, nb) == 0)
	{
		count_a = count_a_rr(a, nb);
		if (more_or_less(b, pos) == 0)
		{
			count_b = count_b_rr(b, nb, pos);
			if (count_b > count_a)
				count_a = count_b;
		}
		else
			count_a += count_b_rrr(b, nb, pos);
	}
	else
		count_a = count_stack_for_rrr(a, b, nb, pos);
	return (count_a + 1);
}
