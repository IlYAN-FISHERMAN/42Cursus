/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 14:14:27 by ilyanar           #+#    #+#             */
/*   Updated: 2023/10/13 17:27:10 by ilyanar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = ft_strlen(dst);
	k = i;
	j = 0;
	while (((i + j) <= dstsize - 2) && (src[j] != '\0'))
	{
		dst[i + j] = src[j];
		j++;
	}
	dst[i + j] = '\0';
	return (k + ft_strlen(src));
}
/*
#include <stdio.h>
#include <string.h>
int	main(void)
{
	char dst[15] = "Hello ";
	char src[] = "wdbhawduawvdbaw,bd,kahwbd,bawldawdorld";

	printf("- Mon test : %zu\n", ft_strlcat(dst, src, 15));
	printf("%s\n", dst);
	//printf("- Vrais fonction : %zu\n", strlcat(dst, src, 15));
	//printf("%s\n", dst);
}
*/
