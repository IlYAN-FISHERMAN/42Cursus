/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 16:51:42 by ilyanar           #+#    #+#             */
/*   Updated: 2024/05/12 21:31:18 by ilyanar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_free_tab(char ***tab)
{
	int	i;

	i = -1;
	if (!*tab)
		return (1);
	while (tab[0][++i])
		free(tab[0][i]);
	free(*tab);
	*tab = NULL;
	return (0);
}
