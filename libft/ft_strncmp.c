/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 17:10:43 by ilyanar           #+#    #+#             */
/*   Updated: 2023/10/14 17:38:23 by ilyanar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while (*s1 == *s2 && n - 1 > 0)
	{
		s1++;
		s2++;
		n--;
	}
	return ((int)*s1 - (int)*s2);
}
/*
#include <stdio.h>
int	main()
{
	char tab1[] = "hellPD";
	char tab2[] = "hellP";
	printf("%d", ft_strncmp(tab1, tab2, 10));
}
*/
