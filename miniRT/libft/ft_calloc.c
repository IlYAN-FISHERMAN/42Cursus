/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 16:05:55 by ilyanar           #+#    #+#             */
/*   Updated: 2024/05/12 21:02:08 by ilyanar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*tab;

	tab = malloc(count * size);
	if (!tab)
		return (NULL);
	ft_bzero(tab, count * size);
	return (tab);
}
