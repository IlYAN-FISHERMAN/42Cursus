/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 11:05:10 by ilyanar           #+#    #+#             */
/*   Updated: 2023/12/21 19:44:45 by ilyanar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

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

int	ft_check_pos(t_listp **stack, int nb)
{
	t_listp	*tmp;

	tmp = *stack;
	if (nb > ft_max(stack))
		return (ft_max(stack));
	else if (nb < ft_min(stack))
		return (ft_min(stack));
	while (tmp)
	{
		if (tmp->content > nb)
		{
			if (tmp->next)
				if (tmp->next->content < nb)
					return (tmp->content);
			if ((*stack)->content < nb && tmp->next == 0)
				return (tmp->content);
		}
		tmp = tmp->next;
	}
	return (0);
}

int	ft_max(t_listp **stack)
{
	t_listp	*tmp;
	int		i;

	tmp = *stack;
	i = tmp->content;
	while (tmp)
	{
		if (tmp->content > i)
			i = tmp->content;
		tmp = tmp->next;
	}
	return (i);
}

int	ft_min(t_listp **stack)
{
	t_listp	*tmp;
	int		i;

	tmp = *stack;
	i = tmp->content;
	while (tmp)
	{
		if (tmp->content < i)
			i = tmp->content;
		tmp = tmp->next;
	}
	return (i);
}

int	check_double(t_listp **stack)
{
	t_listp	*tmp1;
	t_listp	*tmp2;
	int		i;
	int		j;

	j = 0;
	tmp1 = *stack;
	tmp2 = *stack;
	while (tmp1)
	{
		i = tmp1->content;
		while (tmp2)
		{
			if (i == tmp2->content)
				j++;
			if (j > 1)
				return (1);
			tmp2 = tmp2->next;
		}
		j = 0;
		tmp1 = tmp1->next;
		tmp2 = *stack;
	}
	return (0);
}
