/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 18:16:46 by ilyanar           #+#    #+#             */
/*   Updated: 2024/01/06 20:24:11 by ilyanar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

int	ft_sort_a(t_listp **a_stack, t_listp **b_stack)
{
	while (*a_stack)
	{
		if (((*a_stack)->content > (*a_stack)->next->content)
			&& (*a_stack)->content < (*a_stack)->next->next->content)
			ft_sa_sb(a_stack, 1);
		else if (((*a_stack)->content > (*a_stack)->next->content)
			&& (*a_stack)->content > (*a_stack)->next->next->content)
			ft_ra_rb(a_stack, 1);
		else if ((*a_stack)->next->content > (*a_stack)->next->next->content)
			ft_rra_rrb(a_stack, 1);
		else
			break ;
	}
	if (ft_lstsize(*a_stack) == 3 && !*b_stack)
		return (-1);
	return (0);
}

int	ft_free_tab(char **tab)
{
	int	i;

	i = 0;
	while (*(tab + i))
		i++;
	while (i >= 0)
	{
		free(*(tab + i));
		i--;
	}
	free(tab);
	return (0);
}

int	sort_pars(t_listp **a, char **av, int ac)
{
	char	**tab;
	int		i;
	int		li;
	int		nb;
	int		check;

	check = 0;
	i = 0;
	li = 0;
	check = 0;
	while (++i < ac)
	{
		tab = ft_split(av[i], ' ');
		while (*(tab + li))
		{
			nb = ft_atoi_swap(tab[li++], &check);
			ft_lstadd_back(a, ft_lstnew(nb));
			if (check == -1 || check_double(a) == 1)
				return (ft_free_tab(tab) - 1);
		}
		li = 0;
		ft_free_tab(tab);
	}
	return (0);
}

int	push_swap(char **av, int ac)
{
	t_listp	*a_stack;
	t_listp	*b_stack;

	b_stack = 0;
	a_stack = 0;
	if ((sort_pars(&a_stack, av, ac)) == -1)
		return (ft_clear(&a_stack, &b_stack));
	if (pre_sort_check(&a_stack) == 0)
		return (0);
	if (ft_lstsize(a_stack) == 2)
	{
		if (a_stack->content > a_stack->next->content)
			ft_sa_sb(&a_stack, 1);
	}
	else if (ft_lstsize(a_stack) == 3)
		ft_sort_a(&a_stack, &b_stack);
	else if ((ft_lstsize(a_stack)) > 3)
		beginning_algo(&a_stack, &b_stack);
	return ((ft_clear(&a_stack, &b_stack)) + 1);
}
