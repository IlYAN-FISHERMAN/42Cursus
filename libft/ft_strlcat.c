/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 14:14:27 by ilyanar           #+#    #+#             */
/*   Updated: 2024/05/12 21:04:41 by ilyanar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	j = ft_strlen(dst);
	k = ft_strlen(src);
	if (dstsize == 0)
		return (dstsize + k);
	while (src[i] && j + i < dstsize - 1)
	{
		dst[i + j] = src[i];
		i++;
	}
	dst[j + i] = '\0';
	if (j < dstsize)
		return (j + k);
	return (dstsize + k);
}
