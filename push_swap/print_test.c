/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_test.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 13:18:16 by ilyanar           #+#    #+#             */
/*   Updated: 2023/12/12 20:45:11 by ilyanar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

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
