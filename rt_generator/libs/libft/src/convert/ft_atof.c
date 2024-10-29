/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 16:03:39 by ilyanar           #+#    #+#             */
/*   Updated: 2024/09/24 16:37:07 by ilyanar          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libs/libft.h"

float	ft_atof(char *str)
{
	float	nb;
	int		i;
	float	j;
	float	sign;

	i = -1;
	nb = 0;
	j = 0;
	sign = 1;
	if (str[0] == '-' && !++i)
		sign = -1;
	while (str[++i])
	{
		if (str[i] == '.')
		{
			while (str[++i] && ++j)
				nb = (nb * (float)pow(10, j) + (str[i] - 48)) / pow(10, j);
			return (nb * sign);
		}
		nb = nb * 10 + (str[i] - 48);
	}
	return (nb * sign);
}
