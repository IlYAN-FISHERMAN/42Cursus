/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 19:32:13 by ilyanar           #+#    #+#             */
/*   Updated: 2023/10/11 13:22:33 by ilyanar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t		i;
	char		*d;
	const char	*s;

	d = (char *)dst;
	s = (const char *)src;
	i = -1;
	while (i++, i != n)
		d[i] = s[i];
	return (dst);
}
/*
#include <stdio.h>
int	main()
{
	char dst[50]= "hello a tous";
	char src[50]= "bonjour";

	printf("%s", ft_memcpy(dst, src, 2));
}
*/
