/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 18:16:46 by ilyanar           #+#    #+#             */
/*   Updated: 2023/12/14 01:45:41 by ilyanar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

int	sort_pars(t_listp **a_stack, t_listp **b_stack, char **av, int ac)
{
	(*a_stack)->i = 1;
	(*a_stack)->check = 0;
	(*a_stack)->next = NULL;
	while ((*a_stack)->i < ac)
	{
		(*a_stack)->nb = ft_atoi(av[(*a_stack)->i], &(*a_stack)->check);
		if ((*a_stack)->check == -1)
			return (ft_clear(a_stack, b_stack));
		if ((*a_stack)->i == 1)
			(*a_stack)->content = (*a_stack)->nb;
		else
			ft_lstadd_back(a_stack, ft_lstnew((*a_stack)->nb));
		(*a_stack)->i++;
	}
	return (0);
}

int	push_swap(char **av, int ac)
{
	t_listp	*a_stack;
	t_listp	*b_stack;

	b_stack = 0;
	a_stack = malloc(sizeof(t_listp));
	if (!a_stack)
		return (-1);
	if ((sort_pars(&a_stack, &b_stack, av, ac)) == -1)
		return (-1);
	if (ft_lstsize(a_stack) == 2)
	{
		if (a_stack->content > a_stack->next->content)
			ft_sa_sb(&a_stack, 1);
	}
	else if (a_stack->i > 2)
		ft_algo1(&a_stack, &b_stack);
	print_test(&a_stack, &b_stack, a_stack->check);
	return ((ft_clear(&a_stack, &b_stack)) + 1);
}

int	main(int ac, char **av)
{
	if (ac >= 2)
	{
		if ((push_swap(av, ac)) == -1)
		{
			ft_printf("Error");
			return (-1);
		}
	}
	else
	{
		ft_printf("Error");
		return (-1);
	}
	return (0);
}
