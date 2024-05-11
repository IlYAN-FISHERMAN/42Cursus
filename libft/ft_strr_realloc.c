/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strr_realloc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 13:09:18 by ilyanar           #+#    #+#             */
/*   Updated: 2024/05/10 23:07:01 by ilyanar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strr_realloc(char **str, char *neww)
{
	char	**tab;
	int		i;
	int		j;

	i = 0;
	j = -1;
	if (!str || !neww)
		return (NULL);
	while (str[i] != NULL)
		i++;
	tab = ft_calloc(i + 2, sizeof(char *));
	if (!tab)
		return (NULL);
	while (++j < i && i > 0)
		tab[j] = ft_strdup(str[j]);
	tab[j] = ft_strdup(neww);
	if (str && *str)
		ft_free_tab(str);
	return (tab);
}
