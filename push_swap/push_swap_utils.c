/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 10:54:15 by ilyanar           #+#    #+#             */
/*   Updated: 2023/12/23 19:34:35 by ilyanar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

int	more_than3(t_listp **stack)
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
	(void)a2;
	(void)b2;
	t_listp	*tmp1;
	int		nb;
	int		nbr;
	int		lowest;

	tmp1 = *a;
	nbr = 0;
	lowest = 0;
	while (tmp1 != NULL)
	{
		nb = count_stack(a, b, tmp1->content);
		if (nb < nbr || nbr == 0)
		{
			nbr = nb;
			lowest = tmp1->content;
		}
		tmp1 = tmp1->next;
	}
	return (lowest);
}
/*
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
		nb = organize_stacks(a2, b2, tmp1->content, 0);
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
*/
int	ft_clear(t_listp **a_stack, t_listp **b_stack)
{
	if (a_stack)
		ft_lstclear(a_stack, free);
	if (b_stack)
		ft_lstclear(b_stack, free);
	return (-1);
}

int	ft_atoi_swap(const char *str, int *check)
{
	int				i;
	long long int	nb;

	nb = 0;
	i = 1;
	if (*str == '-')
		i = -1;
	if (*str == '-')
		str++;
	else if (*str == '+')
		str++;
	while (*str)
	{
		if (*str >= '0' && *str <= '9')
			nb = nb * 10 + (*str - 48);
		if (!(*str >= '0' && *str <= '9')
			|| (i * nb) > 2147483647 || (i * nb) < -2147483648)
		{
			*check = -1;
			break ;
		}
		str++;
	}
	return (nb * i);
}
