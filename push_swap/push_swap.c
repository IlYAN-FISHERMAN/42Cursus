/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 18:16:46 by ilyanar           #+#    #+#             */
/*   Updated: 2023/12/06 17:09:49 by ilyanar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

int	push_swap(char **av, int ac)
{
	t_listp	*tmp;
	t_listp	*a_stack;
	t_listp	*b_stack;

	a_stack = malloc(sizeof(t_listp));
	b_stack = malloc(sizeof(t_listp));
	if (!a_stack || !b_stack)
		return (0);
	a_stack->check = 0;
	a_stack->i = 1;
	a_stack->nb = ft_atoi(av[a_stack->i], &a_stack->check);
	a_stack->content = a_stack->nb;
	a_stack->i++;
	while (a_stack->i < ac)
	{
		a_stack->nb = ft_atoi(av[a_stack->i], &a_stack->check);
		if (a_stack->check == -1)
			return (-1);
		ft_lstadd_back(&a_stack, ft_lstnew(a_stack->nb));
		a_stack->i++;
	}
	tmp = a_stack;
	while (tmp)
	{
		ft_printf("%d ", tmp->content);
		if (tmp->next == NULL)
			break ;
		else
			tmp = tmp->next;
	}
	return (0);
}

int	main(int ac, char **av)
{
	if (ac >= 2)
	{
		if ((push_swap(av, ac)) == -1)
		{
			ft_printf("ERROR: bad format.\n");
			return (1);
		}
	}
	else
		ft_printf("ERROR: bad format.\n");
	return (0);
}
