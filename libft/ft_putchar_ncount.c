/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_ncount.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 05:25:24 by ilyanar           #+#    #+#             */
/*   Updated: 2023/11/15 05:26:19 by ilyanar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_ncount(char *tab, int *nb)
{
	if (!tab)
	{
		*nb += write(1, "(null)", 6);
		return ;
	}
	while (*tab)
	{
		write(1, &(*tab), 1);
		tab++;
		*nb += 1;
	}
}
