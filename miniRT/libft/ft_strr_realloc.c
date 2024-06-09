/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strr_realloc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 13:09:18 by ilyanar           #+#    #+#             */
/*   Updated: 2024/05/12 22:18:50 by ilyanar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strr_realloc(char **str, char *neww)
{
	char	**tab;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (str)
		while (str[i] != NULL)
			i++;
	tab = ft_calloc(i + 2, sizeof(char *));
	while (i > 0 && j < i)
	{
		tab[j] = ft_strdup(str[j]);
		j++;
	}
	tab[j] = neww;
	ft_free_tab(&str);
	return (tab);
}
