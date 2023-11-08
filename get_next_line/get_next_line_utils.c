/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 14:57:14 by ilyanar           #+#    #+#             */
/*   Updated: 2023/11/08 21:41:02 by ilyanar          ###   ########.fr       */
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

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;

	s3 = (char *)ft_calloc(ft_strlen(s1) + ft_strlen(s2) + 1, sizeof(char));
	if (!s3)
		return (NULL);
	ft_memcpy(s3, s1, ft_strlen(s1));
	ft_memcpy((s3 + ft_strlen(s1)), s2, ft_strlen(s2));
	free((char *)s1);
	return (s3);
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

void	*ft_calloc(size_t count, size_t size)
{
	void	*tab;
	size_t	i;

	i = 0;
	tab = malloc(count * size);
	if (!tab)
		return (NULL);
	while (i != size)
	{
		((char *)tab)[i] = '\0';
	}
	return (tab);
}

int	ft_invalid(char **buffer, int fd)
{
	if (fd < 0 || BUFFER_SIZE < 0 || read(fd, 0, 0) == -1)
	{
		free(*buffer);
		*buffer = 0;
		return (1);
	}
	return (0);
}
