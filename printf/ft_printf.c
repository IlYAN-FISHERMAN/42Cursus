/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 17:47:54 by ilyanar           #+#    #+#             */
/*   Updated: 2023/11/11 05:41:18 by ilyanar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int	test(char *tab)
{
	int	i;

	i = 0;
	while (i < 5)
	{
		write(1, &(*tab), 1);
		tab++;
		i++;
	}
	return (i);
}

void	str_nbr(const char *str, va_list args)
{
	char	c;

	if ((*str == 'd') || (*str == 'i') || (*str == 'u'))
		ft_putnbr(va_arg(args, int));
	else if (*str == 's')
		test(va_arg(args, char *));
	else if (*str == 'c')
	{
		va_arg(args, int);
		write(1, &c, 1);
	}
	return ;
}

void	printt(const char *str, va_list args)
{
	if ((*str == 'c') || (*str == 's') || (*str == 'd') || (*str == 'i') || \
		(*str == 'u'))
		str_nbr(str, args);
	//else if ((*str == 'p'))
	return ;
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		nb;

	nb = 0;
	va_start(args, str);
	while (*str)
	{
		if (*str == '%')
		{
			printt((str + 1), args);
			str++;
			nb++;
		}
		else
			write(1, &(*str), 1);
		str++;
	}
	va_end(args);
	return (nb);
}

int	main(void)
{
	char c = 'd';
	char *str = "pomme";
	int d = 42;
	int i = 2;
	int u = 42;

	ft_printf("j'ai %d %s %cans mon cul %i %u\n", d, str, c, i, u);
}
