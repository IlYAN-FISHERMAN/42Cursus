/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 20:30:13 by ilyanar           #+#    #+#             */
/*   Updated: 2024/05/12 20:30:38 by ilyanar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	count_char(char *str, char c)
{
	int	i;
	int	j;

	i = -1;
	j = 0;
	while (str[++i])
		if (str[i] == c)
			j++;
	return (j);
}
