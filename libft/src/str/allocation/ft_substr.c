/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 18:57:45 by ilyanar           #+#    #+#             */
/*   Updated: 2024/09/24 14:17:21 by ilyanar          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../libs/libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*tab;

	if (start >= ft_strlen(s))
		len = 0;
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	tab = (char *)ft_calloc((len + 1), sizeof(char));
	if (!tab)
		return (NULL);
	ft_memcpy(tab, (s + start), len);
	return (tab);
}
