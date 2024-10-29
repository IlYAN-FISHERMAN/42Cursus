/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 20:27:19 by ilyanar           #+#    #+#             */
/*   Updated: 2024/09/24 14:14:55 by ilyanar          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libs/libft.h"

void	ft_lstadd_front(t_list **lst, t_list *neww)
{
	if (!lst && !neww)
		return ;
	neww->next = *lst;
	*lst = neww;
}
