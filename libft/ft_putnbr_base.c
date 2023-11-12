/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 08:03:59 by ilyanar           #+#    #+#             */
/*   Updated: 2023/11/12 08:04:22 by ilyanar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	putnbr_base(size_t nb, char *base, int *n)
{
	int	len;

	len = ft_strlen(base);
	if (nb < 0)
	{
		write(1, "-", 1);
		ft_putnbr(-nb, n);
	}
	else if (nb > len)
	{
		ft_putnbr(nb / len, n);
		ft_putnbr(nb % len, n);
	}
	else
		ft_putchar(base[len], n);
}
