/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 18:57:45 by ilyanar           #+#    #+#             */
/*   Updated: 2023/10/19 19:12:19 by ilyanar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*tab;

	tab = ft_calloc((len) + 1, sizeof(char));
	if (!tab)
		return (0);
	ft_memcpy(tab, (s + start), len);
	return (tab);
}
/*
#include <stdio.h>
int	main()
{
	char	tab[] = "";
	printf("%s", ft_substr(tab, 6, 0));
}
*/
