/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 20:52:29 by ilyanar           #+#    #+#             */
/*   Updated: 2023/10/16 15:51:04 by ilyanar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	while (*(const char *)s1 == *(const char *)s2 && n > 0)
	{
		s1++;
		s2++;
		n--;
	}
	return (*(int *)s1 - *(int *)s2);
}
/*
#include <stdio.h>
int	main()
{
	char tab[] = "hello";
	char tab2[] = "hello";
	printf("%d" , ft_memcmp(tab, tab2, 3));
}
*/
