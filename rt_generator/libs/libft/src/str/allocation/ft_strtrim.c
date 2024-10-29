/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 00:49:08 by ilyanar           #+#    #+#             */
/*   Updated: 2024/09/24 14:17:16 by ilyanar          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../libs/libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*s2;
	size_t	i;

	if (!s1 || !set)
		return (NULL);
	while (ft_strchr(set, *s1) && *s1 != 0)
		++s1;
	if (*s1 == 0)
		return (s2 = (char *)ft_calloc(1, 1));
	i = ft_strlen(s1);
	while (ft_strchr(set, s1[i]))
		i--;
	s2 = (char *)ft_calloc(i + 2, sizeof(char));
	if (!s2)
		return (NULL);
	ft_memcpy(s2, s1, i + 1);
	return (s2);
}
