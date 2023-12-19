/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 18:50:10 by ilyanar           #+#    #+#             */
/*   Updated: 2023/12/18 20:37:56 by ilyanar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

void	ft_algo1(t_listp **a, t_listp **b)
{
	if (ft_lstcount(a) == 1)
		ft_pa_pb(b, a, 2);
	if (ft_lstcount(a) == 1)
		ft_pa_pb(b, a, 2);
	if (ft_lstcount(a) == 1)
		ft_algo2(a, b);
	if (ft_lstcount(a) == 0)
		ft_sort_a(a, b);
	if (*b)
		ft_repuch(a, b);
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

int	check_rr(t_listp **b, int nb)
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
	if (more_or_less(b, pos) == 0)
		return (1);
	else
		return (0);
}

int	more_or_less(t_listp **a, int nb)
{
	t_listp	*tmp;
	int		i;

	i = 0;
	tmp = *a;
	while (tmp)
	{
		i++;
		if (tmp->content == nb)
			break ;
		tmp = tmp->next;
	}
	if (i <= ft_lstsize(*a) / 2)
		return (0);
	else
		return (1);
}

int	the_lowest(t_listp **a, t_listp **b, t_listp **a2, t_listp **b2)
{
	t_listp	*tmp1;
	int		nb;
	int		nbr;
	int		lowest;

	tmp1 = *a;
	nbr = 0;
	lowest = 0;
	while (tmp1 != NULL)
	{
		ft_lstcpy(a, b, a2, b2);
		nb = ft_sort_b1(a2, b2, tmp1->content, 0);
		if (nb < nbr || nbr == 0)
		{
			nbr = nb;
			lowest = tmp1->content;
		}
		ft_clear(a2, b2);
		tmp1 = tmp1->next;
	}
	return (lowest);
}
