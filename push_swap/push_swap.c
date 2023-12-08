/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 18:16:46 by ilyanar           #+#    #+#             */
/*   Updated: 2023/12/07 23:49:05 by ilyanar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"
#include <stdlib.h>

int	push_swap(char **av, int ac)
{
	t_listp	*tmp;
	t_listp	*tmp1;
	t_listp	*a_stack;
	t_listp	*b_stack;

	a_stack = malloc(sizeof(t_listp));
	b_stack = 0;
	if (!a_stack)
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
	if (ac > 2)
	{
	}
	tmp = a_stack;
	tmp1 = b_stack;
	ft_printf("A_STACK\n");
	while (tmp && a_stack->check != -1)
	{
		ft_printf("%d\n", tmp->content);
		if (tmp->next == NULL)
			break ;
		else
			tmp = tmp->next;
	}
	ft_printf("\nB_STACK\n");
	while (tmp1 && b_stack->check != -1)
	{
		ft_printf("%d\n", tmp1->content);
		if (tmp1->next == NULL)
			break ;
		else
			tmp1 = tmp1->next;
	}
	if (a_stack)
		ft_lstclear(&a_stack, free);
	if (b_stack)
		ft_lstclear(&b_stack, free);
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
