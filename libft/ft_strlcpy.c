/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 12:13:20 by ilyanar           #+#    #+#             */
/*   Updated: 2023/10/12 15:45:27 by ilyanar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dstsize <= 1)
	{
		dst[0] = '\0';
		return (ft_strlen(src));
	}
	while (dstsize - 1 > 0)
	{
		dst[i] = src[i];
		i++;
		dstsize--;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}
/*
#include <string.h>
#include <stdio.h>
int	main()
{
	char dst[6] = "hello";
	char src[] = "bonjour";

	//printf("%zu\n", ft_strlcpy(dst, src, 6));
	//printf("%s", dst);
	//printf("%lu\n", strlcpy(dst, src, 6));
	//printf("%s", dst);
}
*/
