/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 17:47:54 by ilyanar           #+#    #+#             */
/*   Updated: 2023/11/12 08:52:32 by ilyanar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

void	stlen(char *tab, int *nb)
{
	int	i;
	int	j;

	i = -1;
	j = ft_strlen(tab);
	while (++i <= j)
	{
		write(1, &tab[i], 1);
		*nb += 1;
	}
}

int	check(const char *str)
{
	while (*(str++))
		if (*(str - 1) == '%')
			if (!ft_strchr("cspdiuxX%", *(str)))
				return (0);
	return (1);
}

int	str_nbr(const char *str, va_list args, int *nb)
{
	char	c;

	if (check(str) == 0)
		return (0);
	if ((*str == 'd') || (*str == 'i') || (*str == 'u'))
		ft_putnbr(va_arg(args, size_t), nb);
	else if (*str == 's')
		stlen(va_arg(args, char *), nb);
	else if (*str == 'c')
	{
		c = va_arg(args, int);
		write(1, &c, 1);
		*nb += 1;
	}
	return (1);
}

int	who_is_char(const char *str, va_list args, int *nb)
{
	if (!check(str))
		return (0);
	if ((*str == 'c') || (*str == 's') || (*str == 'd') || (*str == 'i')
		|| (*str == 'u'))
		str_nbr(str, args, nb);
	else if ((*str == 'x'))
		putnbr_base(va_arg(args, size_t), "0123456789abcdef", nb);
	else if ((*str == 'X'))
		putnbr_base(va_arg(args, size_t), "0123456789ABCDEF", nb);
	else if ((*str == 'p'))
		print_0x(va_arg(args, long long int), "0123456789abcdef", nb);
	else if (*str == '%')
	{
		write(1, "%", 1);
		*nb += 1;
	}
	return (1);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		nb;

	nb = 0;
	va_start(args, str);
	while (*str++)
	{
		if (*(str - 1) == '%')
		{
			if (!who_is_char((str++), args, &nb))
				break ;
		}
		else
		{
			write(1, (str - 1), 1);
			nb++;
		}
	}
	va_end(args);
	return (nb);
}
/*
#include <stdio.h>
int	main(void)
{
	char c = 'd';
	char *str = "pomme";
	int d = 42;
	int i = 2;
	int u = 42;

	printf("%d\n", ft_printf("j'ai %d %s %cans mon cul %p %x\n", d, str, c, &i, u));
}
*/
