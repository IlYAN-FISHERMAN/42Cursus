/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 18:00:17 by ilyanar           #+#    #+#             */
/*   Updated: 2024/09/24 14:15:31 by ilyanar          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libs/libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*body;

	body = malloc(sizeof(t_list));
	if (!body)
		return (NULL);
	body->content = content;
	body->next = NULL;
	return (body);
}
