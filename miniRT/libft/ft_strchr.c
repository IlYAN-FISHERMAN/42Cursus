/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 17:34:25 by ilyanar           #+#    #+#             */
/*   Updated: 2024/05/12 21:04:23 by ilyanar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	if (!(unsigned char)c)
		return ((char *)s + ft_strlen(s));
	while (*s && *s != (unsigned char)c)
		s++;
	if (*s == '\0')
		return (0);
	return ((char *)s);
}
