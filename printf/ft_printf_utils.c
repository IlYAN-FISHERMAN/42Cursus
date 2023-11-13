/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 01:58:36 by ilyanar           #+#    #+#             */
/*   Updated: 2023/11/13 22:09:52 by ilyanar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

void	ft_putchar(char c, int *nb)
{
	*nb += write(1, &c, 1);
}

void	ft_putnbr(int nbr, int *n)
{
	long	nb;

	nb = nbr;
	if (nb < 0)
	{
		write(1, "-", 1);
		*n += 1;
		nb = nb * -1;
	}
	if (nb > 9)
	{
		ft_putnbr(nb / 10, n);
		ft_putnbr(nb % 10, n);
	}
	else
		ft_putchar(nb + '0', n);
}

void	putnbr_base(long nb, char *base, int *n)
{
	if (nb > 16)
	{
		putnbr_base(nb / 16, base, n);
		putnbr_base(nb % 16, base, n);
	}
	else
		ft_putchar(base[nb], n);
}

void	print_0x(unsigned long long int nb, char *base, int *n)
{
	write(1, "0x", 2);
	*n += 2;
	printf_addr(nb, base, n);
}

void	printf_addr(unsigned long long int nb, char *base, int *n)
{
	if (nb >= 16)
	{
		printf_addr(nb / 16, base, n);
		printf_addr(nb % 16, base, n);
	}
	else
		ft_putchar(base[nb], n);
}
