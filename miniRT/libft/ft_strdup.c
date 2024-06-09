/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 18:34:58 by ilyanar           #+#    #+#             */
/*   Updated: 2024/05/12 21:04:29 by ilyanar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*tab;

	tab = ft_calloc(ft_strlen(s) + 1, sizeof(char));
	if (!tab)
		return (0);
	ft_memcpy(tab, s, ft_strlen(s));
	return (tab);
}
