/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 11:35:12 by ilyanar           #+#    #+#             */
/*   Updated: 2023/12/22 22:47:14 by ilyanar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

int	organize_stacks(t_listp **a, t_listp **b, int nb, int check)
{
	int	count;

	count = 0;
	if (more_or_less(a, nb) == 0)
	{
		while ((*a)->content != nb)
		{
			if (check_rr(b, nb) == 1)
				count += ft_rr(a, b, 1 * check);
			else
				count += ft_ra_rb(a, 1 * check);
		}
	}
	else
		count += sort_a_rrr(a, b, nb, check);
	return (count += organize_b(a, b, nb, check));
}

int	sort_a_rrr(t_listp **a, t_listp **b, int nb, int check)
{
	int	count;

	count = 0;
	while ((*a)->content != nb)
	{
		if (check_rrr(b, nb) == 1)
			ft_rrr(a, b, 1 * check);
		else
			ft_rra_rrb(a, 1 * check);
		count++;
	}
	return (count);
}

int	organize_b(t_listp **a, t_listp **b, int nb, int check)
{
	int	count;
	int	pos;

	count = 0;
	pos = ft_check_pos(b, nb);
	if (more_or_less(b, pos) == 0 && nb > ft_max(b))
		while ((*b)->content != ft_max(b))
			count += ft_ra_rb(b, 2 * check);
	else if (more_or_less(b, pos) == 1 && nb > ft_max(b))
		while ((*b)->content != ft_max(b))
			count += ft_rra_rrb(b, 2 * check);
	else if (more_or_less(b, pos) == 0 && nb < ft_min(b))
		while (ft_lstlast(*b)->content != ft_min(b))
			count += ft_ra_rb(b, 2 * check);
	else if (more_or_less(b, pos) == 1 && nb < ft_min(b))
		while (ft_lstlast(*b)->content != ft_min(b))
			count += ft_rra_rrb(b, 2 * check);
	else if (more_or_less(b, pos) == 0)
		while (ft_lstlast(*b)->content != pos)
			count += ft_ra_rb(b, 2 * check);
	else if (more_or_less(b, pos) == 1)
		while (ft_lstlast(*b)->content != pos)
			count += ft_rra_rrb(b, 2 * check);
	return (count += ft_pa_pb(b, a, 2 * check));
}

int	pre_sort_check(t_listp **a)
{
	t_listp	*tmp;

	tmp = *a;
	while (tmp)
	{
		if (tmp->next)
			if (tmp->content > tmp->next->content)
				return (1);
		tmp = tmp->next;
	}
	return (0);
}
