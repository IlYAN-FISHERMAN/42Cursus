/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 17:22:47 by ilyanar           #+#    #+#             */
/*   Updated: 2023/10/22 18:13:17 by ilyanar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		i;
	t_list	*tmp;

	i = 1;
	if (!lst)
		return (0);
	tmp = lst->next;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}
