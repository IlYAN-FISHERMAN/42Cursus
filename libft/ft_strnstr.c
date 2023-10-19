/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 22:35:42 by ilyanar           #+#    #+#             */
/*   Updated: 2023/10/19 03:18:30 by ilyanar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;

	i = 0;
	if (ft_strlen(needle) == 0)
		return ((char *)haystack);
	while (len > 0)
	{
		if (*haystack == *needle)
		{
			while (*(haystack + i) == *(needle + i) && i < len - 1)
				i++;
			if (*(needle + i) == '\0')
				return ((char *)haystack);
			i = 0;
		}
		haystack++;
		len--;
	}
	return (0);
}
/*
#include <stdio.h>
int	main()
{
	char tab[] = "A";
	//char tab2[] = "coucou";

	printf(" M_fonction : %s\n", ft_strnstr(tab, tab, 2));
	printf("V_fonction : %s\n", strnstr(tab, tab, 2));
}
*/
