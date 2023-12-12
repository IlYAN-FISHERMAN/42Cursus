/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_set2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 13:45:01 by ilyanar           #+#    #+#             */
/*   Updated: 2023/12/12 14:16:51 by ilyanar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

void	ft_rra_rrb(t_listp **stack, int check)
{
	t_listp	*tmp1;
	t_listp	*tmp2;

	tmp1 = *stack;
	if ((*stack)->next == NULL)
		return ;
	while (tmp1)
	{
		if (tmp1->next->next == NULL)
		{
			tmp2 = tmp1->next;
			tmp1->next = 0;
			ft_lstadd_front(stack, tmp2);
			break ;
		}
		tmp1 = tmp1->next;
	}
	if (check == 1)
		ft_printf("rra\n");
	if (check == 2)
		ft_printf("rrb\n");
}
