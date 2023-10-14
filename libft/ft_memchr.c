/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 17:39:22 by ilyanar           #+#    #+#             */
/*   Updated: 2023/10/14 18:14:17 by ilyanar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	while ((*(const char *)s != (unsigned char)c) && (n - 1 > 0))
	{
		s++;
		n--;
	}
	if (*(char *)s == '\0')
		return (0);
	return ((void *)s);
}
/*
#include <stdio.h>
int	main()
{
	char tab[] = "gello uys";
	char c = 'g';

	printf("%s", (char *)ft_memchr(tab, c, 10));
}
*/
