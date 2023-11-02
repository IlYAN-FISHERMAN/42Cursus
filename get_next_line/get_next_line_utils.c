/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 14:57:14 by ilyanar           #+#    #+#             */
/*   Updated: 2023/10/23 14:57:16 by ilyanar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	ft_bzero(void *s, size_t n)
{
	size_t		i;
	char		*tab;

	i = 0;
	tab = (char *)s;
	while (i != n)
	{
		tab[i] = '\0';
		i++;
	}
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*tab;

	tab = malloc(count * size);
	if (!tab)
		return (NULL);
	ft_bzero(tab, count * size);
	return (tab);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t		i;
	char		*d;
	const char	*s;

	d = (char *)dst;
	s = (const char *)src;
	i = -1;
	if (!dst && !src)
		return (NULL);
	while (i++, i != n)
		d[i] = s[i];
	return (dst);
}

char	*ft_strdup(const char *s)
{
	char	*tab;

	tab = ft_calloc(ft_strlen(s) + 1, sizeof(char));
	if (!tab)
		return (0);
	ft_memcpy(tab, s, ft_strlen(s));
	return (tab);
}