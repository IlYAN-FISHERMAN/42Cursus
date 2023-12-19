/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 19:09:16 by ilyanar           #+#    #+#             */
/*   Updated: 2023/12/18 22:27:21 by ilyanar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

int	check_rrr(t_listp **b, int nb)
{
	int	pos;

	pos = ft_check_pos(b, nb);
	if (nb > ft_max(b))
	{
		if ((*b)->content == ft_max(b))
			return (0);
	}
	if (nb < ft_min(b))
	{
		if (ft_lstlast(*b)->content == ft_min(b))
			return (0);
	}
	if (more_or_less(b, pos) == 1)
		return (1);
	else
		return (0);
}

int	ft_sort_b3(t_listp **a, t_listp **b, int nb, int check)
{
	int	count;
	int	pos;

	count = 0;
	pos = ft_check_pos(b, nb);
	if (check != 0)
		ft_printf("POS : %d\n", pos);
	if (more_or_less(b, pos) == 0)
	{
		while (ft_lstlast(*b)->content != pos)
		{
			ft_ra_rb(b, check);
			count++;
		}
	}
	else
	{
		while (ft_lstlast(*b)->content != pos)
		{
			ft_rra_rrb(b, check);
			count++;
		}
	}
	ft_pa_pb(b, a, check);
	count++;
	return (count);
}

void	ft_finish_b(t_listp **b)
{
	int	max;

	max = ft_max(b);
	if (more_or_less(b, max) == 0)
	{
		while (((*b)->content) != max)
			ft_ra_rb(b, 2);
	}
	else
	{
		while (((*b)->content) != max)
			ft_rra_rrb(b, 2);
	}
}

void	ft_repuch(t_listp **a, t_listp **b)
{
	(void)a;
	(void)b;
	return ;
}
