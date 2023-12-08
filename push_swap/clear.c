/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 15:07:47 by ilyanar           #+#    #+#             */
/*   Updated: 2023/12/08 15:09:43 by ilyanar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

int	ft_clear(t_listp **a_stack, t_listp **b_stack)
{
	if (a_stack)
		ft_lstclear(a_stack, free);
	if (b_stack)
		ft_lstclear(b_stack, free);
	return (-1);
}
