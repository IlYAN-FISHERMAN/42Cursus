/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_tab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 13:21:32 by ilyanar           #+#    #+#             */
/*   Updated: 2024/09/24 14:18:03 by ilyanar          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../libs/libft.h"

void	ft_rev_tab(char *tab)
{
	size_t	i;
	size_t	j;
	char	temp;

	j = 0;
	i = ft_strlen(tab) - 1;
	while (j <= i && i > 0)
	{
		temp = tab[j];
		tab[j] = tab[i];
		tab[i] = temp;
		j++;
		i--;
	}
}
