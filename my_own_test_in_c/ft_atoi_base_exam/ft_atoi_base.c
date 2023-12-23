/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 15:39:36 by ilyanar           #+#    #+#             */
/*   Updated: 2023/12/19 20:18:13 by ilyanar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_check(char c, int base)
{
	char tab1[] = "0123456789abcdef";
	char tab2[] = "0123456789ABCDEF";

	while (base--)
		if (c == tab1[base] || c == tab2[base])
			return (1);
	return (0);
}

int	ft_value(char c)
{
	if (c >= '0' && c <= '9')
		return (c - '0');
	if (c >= 'a' && c <= 'f')
		return (c - 'a' + 10);
	if (c >= 'A' && c <= 'F')
		return (c - 'A' + 10);
	return (0);
}

int	ft_atoi_base(const char *str, int base)
{
	int	i;
	int	nb;

	nb = 0;
	i = 1;
	while ((*str <= 32))
		str++;
	if (*str == '-')
	{
		i = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (ft_check(*str, base))
		nb = nb * base + (ft_value(*str++));
	return (nb * i);
}

int	main(int ac, char **av)
{
	int	nb;
	int	i;

	i = 0;
	nb = 0;
	if (ac == 3)
	{
		while (av[2][i] >= '0' && av[2][i] <= '9')
		{
			nb = nb * 10 + (av[2][i] - 48);
			i++;
		}
		printf("M_fonction : %d\n", ft_atoi_base(av[1], nb));
	}
}
