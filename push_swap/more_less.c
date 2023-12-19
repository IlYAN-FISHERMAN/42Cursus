/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_less.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 18:57:31 by ilyanar           #+#    #+#             */
/*   Updated: 2023/12/18 22:52:43 by ilyanar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

void	ft_algo2(t_listp **a, t_listp **b)
{
	t_listp	*a2;
	t_listp	*b2;
	int		nb;

	a2 = 0;
	b2 = 0;
	while (ft_lstcount(a) != 0)
	{
		ft_printf(" ---------- \n| PREVIOUS |\n ---------- \n");
		print_test(a, b, 1);
		nb = the_lowest(a, b, &a2, &b2);
		ft_printf("lowest : %d\n\n", nb);
		ft_printf(" ------- \n| MOVES |\n ------- \n");
		ft_sort_b1(a, b, nb, 2);
		ft_printf(" ------- \n| AFTER |\n ------- \n\n");
		print_test(a, b, 1);
	}
	ft_finish_b(b);
}

void	ft_lstcpy(t_listp **a, t_listp **b, t_listp **a2, t_listp **b2)
{
	t_listp	*tmp;

	tmp = *a;
	while (tmp)
	{
		ft_lstadd_back(a2, ft_lstnew(tmp->content));
		tmp = tmp->next;
	}
	tmp = *b;
	while (tmp)
	{
		ft_lstadd_back(b2, ft_lstnew(tmp->content));
		tmp = tmp->next;
	}
}

int	ft_sort_b1(t_listp **a, t_listp **b, int nb, int check)
{
	int	count;

	count = 0;
	if (more_or_less(a, nb) == 0)
	{
		while ((*a)->content != nb)
		{
			if (check_rr(b, nb) == 1)
				ft_rr(a, b, check);
			else
				ft_ra_rb(a, check);
			count++;
		}
	}
	else
		count += ft_sort_b2(a, b, nb, check);
	count += ft_sort_b3(a, b, nb, check);
	return (count);
}

int	ft_sort_b2(t_listp **a, t_listp **b, int nb, int check)
{
	int	count;

	count = 0;
	while (ft_lstlast(*a)->content != nb)
	{
		if (check_rrr(b, nb) == 1)
			ft_rrr(a, b, check);
		else
			ft_rra_rrb(a, check);
		count++;
	}
	return (count);
}

int	ft_check_pos(t_listp **stack, int nb)
{
	int		pos;
	t_listp	*tmp;

	tmp = *stack;
	pos = tmp->content;
	while (tmp)
	{
		if (tmp->next)
		{
			if (nb > tmp->content && nb < ft_lstlast(*stack)->content)
				return (ft_lstlast(*stack)->content);
			else if ((nb < tmp->content && nb > tmp->next->content)
				|| (nb > tmp->content && nb < tmp->next->content))
				pos = tmp->content;
		}
		tmp = tmp->next;
	}
	return (pos);
}
