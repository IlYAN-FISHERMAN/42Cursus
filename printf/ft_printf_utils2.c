/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 22:12:15 by ilyanar           #+#    #+#             */
/*   Updated: 2023/11/15 05:13:57 by ilyanar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

void	putnbr_u(unsigned int nb, int *n)
{
	if (nb > 9)
	{
		putnbr_u(nb / 10, n);
		putnbr_u(nb % 10, n);
	}
	else
		ft_putchar(nb + '0', n);
}
