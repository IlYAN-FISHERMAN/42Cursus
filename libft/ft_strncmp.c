/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 22:33:55 by ilyanar           #+#    #+#             */
/*   Updated: 2024/05/12 21:05:05 by ilyanar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while ((s1[i] || s2[i]) && n != i)
	{
		if (s1[i] != s2[i])
		{
			if (s1[i] < 0)
				return (1);
			if (s2[i] < 0)
				return (-1);
			return (s1[i] - s2[i]);
		}
		i++;
	}
	return (0);
}
