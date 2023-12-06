/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 23:10:28 by ilyanar           #+#    #+#             */
/*   Updated: 2023/12/06 16:37:14 by ilyanar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_listp *lst)
{
	int		i;
	t_listp	*tmp;

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
