/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 17:47:54 by ilyanar           #+#    #+#             */
/*   Updated: 2023/11/14 07:12:22 by ilyanar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

void	stlen(char *tab, int *nb)
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

int	check(const char *str)
{
	while (*str)
	{
		if (*(str) == '%')
		{
			str++;
			if (!ft_strchr("cspdiuxX%", *(str)))
				return (0);
		}
		str++;
	}
	return (1);
}

void	printf_c(char c, int *nb)
{
	if (write(1, &c, 1) > 0)
		*nb += 1;
}

void	who_is_char(const char *str, va_list *args, int *nb)
{
	if (*str == 'c')
		printf_c(va_arg(*args, int), nb);
	if ((*str == 'i') || (*str == 'd'))
		ft_putnbr(va_arg(*args, int), nb);
	if ((*str == 's'))
		stlen(va_arg(*args, char *), nb);
	if ((*str == 'u'))
		putnbr_u(va_arg(*args, unsigned int), nb);
	if ((*str == 'x'))
		putnbr_base(va_arg(*args, unsigned int), "0123456789abcdef", nb);
	if ((*str == 'X'))
		putnbr_base(va_arg(*args, unsigned int), "0123456789ABCDEF", nb);
	if ((*str == 'p'))
		print_0x(va_arg(*args, long long int), "0123456789abcdef", nb);
	if (*str == '%')
	{
		write(1, "%", 1);
		*nb += 1;
	}
}

int	ft_printf(const char *str, ...)
{
	int		nb;
	va_list	args;

	nb = 0;
	if (!check(str))
		return (0);
	va_start(args, str);
	while (*str)
	{
		if (*str == '%')
		{
			who_is_char((str + 1), &args, &nb);
			str += 2;
		}
		else
		{
			write(1, &(*str), 1);
			nb++;
			str++;
		}
	}
	va_end(args);
	return (nb);
}
/*
#include <stdio.h>
int	main(void)
{
	int nb = 4200;
	printf("byte_read ->_%d\n\n\n", printf("V-STRING ->_%-6dtest\n\n", nb));	
	printf("byte_read ->_%d\n\n", ft_printf("F-STRING ->_%2d\n\n", nb));
}
*/
