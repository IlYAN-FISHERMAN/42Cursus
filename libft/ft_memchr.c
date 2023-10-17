/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 17:39:22 by ilyanar           #+#    #+#             */
/*   Updated: 2023/10/18 01:23:49 by ilyanar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;
	char	*str;

	str = (char *)s;
	i = 0;
	while ((i < n))
	{
		if (str[i] == c)
			return (str + i);
		i++;
	}
	return (0);
}
/*
#include <stdio.h>

int	main()
{
	int tab[] = {-49, 49, 1, -1, 0, -2, 2};

	printf("M_fonction : %s\n", (char *)ft_memchr(tab, -1, 7));
	printf("V_fonction : %s\n", (char *)memchr(tab, -1, 7));
}
*/
