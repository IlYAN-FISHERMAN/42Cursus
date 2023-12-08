/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 15:39:36 by ilyanar           #+#    #+#             */
/*   Updated: 2023/12/08 13:51:24 by ilyanar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int	ft_atoi(const char *str, int *check)
{
	int	i;
	int	nb;

	nb = 0;
	i = 1;
	if (*str == '-')
		i = -1;
	if (*str == '-')
		str++;
	else if (*str == '+')
		str++;
	while (*str)
	{
		if (*str >= '0' && *str <= '9')
		{
			nb = nb * 10 + (*str - 48);
			str++;
		}
		else
		{
			*check = -1;
			break ;
		}
	}
	return (nb * i);
}
/*
#include <stdio.h>
#include <stdlib.h>
int	main()
{
	char tab[] = "-152";

	printf("M_fonction : %d\n", ft_atoi(tab));
	printf("V_fonction : %d\n", atoi(tab));
}
*/
