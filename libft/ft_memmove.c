/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 17:22:15 by ilyanar           #+#    #+#             */
/*   Updated: 2023/10/11 17:40:09 by ilyanar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t		i;
	char		*d;
	const char	*s;

	d = (char *)dst;
	s = (const char *)src;
	i = 0;
	if (d > s)
	{
		while (i < len)
		{
			d[len] = s[len];
			len--;
		}
		return (dst);
	}
	else
	{
		while (i < len)
		{
			d[i] = s[i];
			i++;
		}
		return (dst);
	}
}
