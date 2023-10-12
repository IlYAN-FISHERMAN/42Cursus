/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 14:14:27 by ilyanar           #+#    #+#             */
/*   Updated: 2023/10/12 16:55:04 by ilyanar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

size_t ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;

	i = ft_strlen(src);
	j = 0;
	while ((i + j <= dstsize - 1) || ( src[j] == '\0'))
	{
		dst[i + j] = src[j];
		j++;
	}
	dst[i + j] = '\0';
	return (ft_strlen(dst));
}

#include <stdio.h>
#include <string.h>
int	main()
{
	char dst[20] = "Hello ";
	char src[] = "Worlddawsdawsdawdsawdawd!";

	printf("%zu\n", ft_strlcat(dst, src, 20));
	printf("%s", dst);
	//printf("%zu\n", strlcat(dst, src, 20));
	//printf("%s", dst);
}
