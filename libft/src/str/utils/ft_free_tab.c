/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 16:51:42 by ilyanar           #+#    #+#             */
/*   Updated: 2024/09/24 14:17:39 by ilyanar          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../libs/libft.h"

int	ft_free_tab(char ***tab, void (*f)(void *))
{
	int	i;

	i = -1;
	if (!tab || !*tab)
		return (1);
	while (tab[0][++i])
		f(tab[0][i]);
	f(*tab);
	*tab = NULL;
	return (0);
}
