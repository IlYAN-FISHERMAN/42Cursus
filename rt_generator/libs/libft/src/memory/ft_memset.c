/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 17:54:06 by ilyanar           #+#    #+#             */
/*   Updated: 2024/05/12 21:03:25 by ilyanar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memset(void *b, int c, size_t len)
{
	size_t				i;
	unsigned char		*tab;

	tab = (unsigned char *)b;
	i = -1;
	while (i++, i != len)
		tab[i] = c;
	return (tab);
}
