/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 13:01:39 by ilyanar           #+#    #+#             */
/*   Updated: 2024/11/25 16:38:19 by ilyanar          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../push_swap.h"

void	ft_error(void)
{
	ft_printf("Error\n");
	exit(EXIT_FAILURE);
}

int	ft_instruction(t_listp **a, t_listp **b, char *tab)
{
	if (tab[0] == 's' && tab[1] == 'a' && tab[2] == '\n')
		return (ft_sa_sb(a, 0));
	if (tab[0] == 's' && tab[1] == 'b' && tab[2] == '\n')
		return (ft_sa_sb(b, 0));
	if (tab[0] == 'p' && tab[1] == 'a' && tab[2] == '\n')
		return (ft_pa_pb(a, b, 0));
	if (tab[0] == 'p' && tab[1] == 'b' && tab[2] == '\n')
		return (ft_pa_pb(b, a, 0));
	if (tab[0] == 'r' && tab[1] == 'a' && tab[2] == '\n')
		return (ft_ra_rb(a, 0));
	if (tab[0] == 'r' && tab[1] == 'b' && tab[2] == '\n')
		return (ft_ra_rb(b, 0));
	if (tab[0] == 'r' && tab[1] == 'r' && tab[2] == '\n')
		return (ft_rr(a, b, 0));
	if (tab[0] == 'r' && tab[1] == 'r' && tab[2] == 'a' && tab[3] == '\n')
		return (ft_rra_rrb(a, 0));
	if (tab[0] == 'r' && tab[1] == 'r' && tab[2] == 'b' && tab[3] == '\n')
		return (ft_rra_rrb(b, 0));
	if (tab[0] == 'r' && tab[1] == 'r' && tab[2] == 'r' && tab[3] == '\n')
		return (ft_rrr(a, b, 0));
	ft_error();
	return (-1);
}

void	ft_ok_ko(t_listp **a, t_listp **b)
{
	if (pre_sort_check(a) == 0 && !*b)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
}

int	main(int ac, char **av)
{
	char	*tab;
	t_listp	*a;
	t_listp	*b;

	a = 0;
	b = 0;
	if (ac <= 1)
		return (ft_clear(&a, &b));
	tab = get_next_line(0);
	if ((sort_pars(&a, av, ac)) == -1)
	{
		ft_printf("Error\n");
		return (ft_clear(&a, &b));
	}
	while (tab != NULL)
	{
		if (ft_instruction(&a, &b, tab) == -1)
			break ;
		free(tab);
		tab = get_next_line(0);
	}
	if (tab)
		free(tab);
	print_test(&a, &b, 1);
	return (ft_clear(&a, &b) + 1);
}

void	print_test(t_listp **a_stack, t_listp **b_stack, int check)
{
	t_listp	*tmp;
	t_listp	*tmp1;

	if (*a_stack)
	{
		if (check != -1)
			ft_printf("A_STACK\n");
		tmp = (*a_stack);
		while (tmp && check != -1)
		{
			ft_printf("%d\n", tmp->content);
			if (tmp->next == NULL)
				break ;
			else
				tmp = tmp->next;
		}
	}
	if (*b_stack)
	{
		if (check != -1)
			ft_printf("\nB_STACK\n");
		tmp1 = (*b_stack);
		while (tmp1 && check != -1)
		{
			ft_printf("%d\n", tmp1->content);
			if (tmp1->next == NULL)
				break ;
			else
				tmp1 = tmp1->next;
		}
	}
}
