/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 18:00:17 by ilyanar           #+#    #+#             */
/*   Updated: 2023/12/06 16:27:27 by ilyanar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../push_swap.h"

t_listp	*ft_lstnew(int content)
{
	t_listp	*body;

	body = malloc(sizeof(t_listp));
	if (!body)
		return (NULL);
	body->content = content;
	body->next = NULL;
	return (body);
}
/*
int	main(void)
{
	char tab[] = "hello";
	ft_lstnew(tab);
}
*/
