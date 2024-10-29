/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 22:31:57 by ilyanar           #+#    #+#             */
/*   Updated: 2024/09/24 14:14:59 by ilyanar          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libs/libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*tmp;
	t_list	*next;

	if (!lst || ! del)
		return ;
	tmp = *lst;
	while (tmp)
	{
		next = tmp->next;
		if (tmp->content != NULL)
			del(tmp->content);
		free(tmp);
		tmp = next;
	}
	*lst = NULL;
}
