/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 01:58:36 by ilyanar           #+#    #+#             */
/*   Updated: 2024/03/24 10:24:55 by ilyanar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

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
		ft_putcharr(nb + '0', n);
}
