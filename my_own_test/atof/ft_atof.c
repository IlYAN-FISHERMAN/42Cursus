/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 16:03:39 by ilyanar           #+#    #+#             */
/*   Updated: 2024/10/01 16:41:17 by ilyanar          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "math.h"

double	ft_atof(char *str)
{
	double	nb;
	int		i;
	double	j;
	double	k;
	double	sign;

	i = -1;
	nb = 0;
	j = 1;
	k = 1;
	sign = 1;
	if (str[0] == '-' && !++i)
		sign = -1;
	while (str[++i])
	{
		if (str[i] == '.')
		{
			while (str[++i])
			{
				j *= 0.1;
				k *= 10;
				nb = (nb * k + (str[i] - 48)) * j;
			}
			return (nb * sign);
		}
		nb = nb * 10 + (str[i] - 48);
	}
	return (nb * sign);
}

#include <stdio.h>
#include <stdlib.h>

int main(int ac, char **av)
{
	int i;

	i = 0;
	if (ac != 2 && i == 0)
		return (-1);
	for (double d = 0; d < 500000000; d++)
	{
		/*printf("%f\n", ft_atof(av[1]));*/
		i = ft_atof(av[1]);
		i += 10;
		/*strtof(av[1], NULL);*/
		/*printf("%f\n", strtof(av[1], NULL));*/
	}
}
