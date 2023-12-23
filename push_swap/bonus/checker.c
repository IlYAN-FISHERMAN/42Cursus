/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 13:01:39 by ilyanar           #+#    #+#             */
/*   Updated: 2023/12/22 15:03:24 by ilyanar          ###   ########.fr       */
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
	if (tab[0] == 's' && tab[1] == 'a')
}

int	main(int ac, char **av)
{
	char	*tab;
	t_listp	*a;
	t_listp	*b;

	a = 0;
	b = 0;
	tab = get_next_line(0);
	if ((sort_pars(&a, &b, av, ac)) == -1)
		ft_error();
	while (tab != NULL)
	{
		tab = get_next_line(0);
		ft_instruction(&a, &b, tab);
	}
	return (0);
}
