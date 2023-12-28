/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 20:01:06 by ilyanar           #+#    #+#             */
/*   Updated: 2023/12/25 03:01:07 by ilyanar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

int	count_stack_for_rrr(t_listp **a, t_listp **b, int nb, int pos)
{
	int	count_a;
	int	count_b;

	count_a = count_a_rrr(a, nb);
	count_a = count_a_rrr(a, nb);
	if (more_or_less(b, pos) == 1)
	{
		count_b = count_b_rrr(b, nb, pos);
		if (count_b > count_a)
			count_a = count_b;
	}
	else
		count_a += count_b_rr(b, nb, pos);
	return (count_a);
}

int	count_a_rr(t_listp **a, int nb)
{
	t_listp	*tmp;
	int		count;

	count = 0;
	tmp = *a;
	while (tmp->content != nb)
	{
		if (tmp->content != nb)
			count++;
		tmp = tmp->next;
	}
	return (count);
}

int	count_a_rrr(t_listp **a, int nb)
{
	t_listp	*tmp;
	int		count;

	count = 0;
	tmp = *a;
	while (tmp->content != nb)
		tmp = tmp->next;
	while (tmp)
	{
		count++;
		tmp = tmp->next;
	}
	return (count);
}

int	count_b_rr(t_listp **b, int nb, int pos)
{
	t_listp	*tmp;
	int		count;

	count = 0;
	tmp = *b;
	while (tmp->content != pos)
	{
		if (tmp->content != nb)
			count++;
		tmp = tmp->next;
	}
	if (nb > pos)
		count--;
	return (count + 1);
}

int	count_b_rrr(t_listp **b, int nb, int pos)
{
	t_listp	*tmp;
	int		count;

	count = 0;
	tmp = *b;
	while (tmp->content != pos)
		tmp = tmp->next;
	while (tmp)
	{
		tmp = tmp->next;
		count++;
	}
	if (nb > pos)
		count++;
	return (count);
}
