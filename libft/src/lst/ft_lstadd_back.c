/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 19:03:56 by ilyanar           #+#    #+#             */
/*   Updated: 2024/09/24 14:14:44 by ilyanar          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libs/libft.h"

void	ft_lstadd_back(t_list **lst, t_list *neww)
{
	if (!lst || !neww)
		return ;
	if (!*lst)
		*lst = neww;
	else
		ft_lstlast(*lst)->next = neww;
}
