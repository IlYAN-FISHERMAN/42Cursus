/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 11:35:07 by ilyanar           #+#    #+#             */
/*   Updated: 2023/12/23 11:46:59 by ilyanar          ###   ########.fr       */
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
	t_listp	*a2;
	t_listp	*b2;
	int		nb;

	a2 = 0;
	b2 = 0;
	while (more_than3(a) != 0)
	{
		nb = the_lowest(a, b, &a2, &b2);
		//ft_printf("\n");
		//print_test(a, b, 1);
		//ft_printf("\n\nthe lowest : %d\n\n", nb);
		//ft_printf("MOVES\n");
		organize_stacks(a, b, nb, 1);
	}
	//ft_printf("\nFIN\n\n");
	ft_finish_b(b, 1);
}

void	ft_finish_b(t_listp **b, int check)
{
	int	max;

	max = ft_max(b);
	if (more_or_less(b, max) == 0)
	{
		while (((*b)->content) != max)
			ft_ra_rb(b, 2 * check);
	}
	else
	{
		while (((*b)->content) != max)
			ft_rra_rrb(b, 2 * check);
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
