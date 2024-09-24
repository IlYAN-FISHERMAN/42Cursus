/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strr_realloc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 13:09:18 by ilyanar           #+#    #+#             */
/*   Updated: 2024/09/24 14:17:11 by ilyanar          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../libs/libft.h"

char	**ft_strr_realloc(char **str, char *neww)
{
	char	**tab;
	int		i;
	int		j;

	i = 0;
	j = -1;
	while (str && str[i])
		i++;
	tab = ft_calloc(i + 2, sizeof(char *));
	if (!tab)
		return (NULL);
	while (++j < i && i > 0)
		tab[j] = str[j];
	tab[j] = neww;
	ft_free_tab(&str, free);
	return (tab);
}
