/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 18:50:10 by ilyanar           #+#    #+#             */
/*   Updated: 2023/12/14 22:55:30 by ilyanar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

void	ft_algo1(t_listp **a, t_listp **b)
{
	t_listp	*tmp;
	int		nb;

	(void)tmp;
	(void)nb;
	if (ft_lstsize(*a) > 3)
		ft_pa_pb(b, a, 2);
	if (ft_lstsize(*a) > 3)
		ft_pa_pb(b, a, 2);
	while (ft_lstcount(a) == 1)
	{
		break ;
		//tmp = more_less(a, b);
	}
	if (ft_lstcount(a) == 0)
		ft_sort_a(a, b);
}

int	ft_lstcount(t_listp **stack)
{
	int		i;
	t_listp	*tmp;

	i = 1;
	if (!*stack)
		return (0);
	tmp = (*stack)->next;
	while (tmp)
	{
		i++;
		if (i > 3)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}
