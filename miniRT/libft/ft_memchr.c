/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 17:39:22 by ilyanar           #+#    #+#             */
/*   Updated: 2024/05/12 21:03:10 by ilyanar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;

	i = 0;
	while ((i < n))
	{
		if (*(unsigned char *)(s + i) == (unsigned char)c)
			return ((void *)s + i);
		i++;
	}
	return (NULL);
}
