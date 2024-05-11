#include <stdarg.h>
#include <unistd.h>

void	ft_putchar(int *i, char c)
{
	*i += write(1, &c, 1);
}

void	put_nbr_hexa(int *i, long int nb, char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	if (nb < 0)
	{
		*i += 2;
		write (1, "-", 1);
		put_nbr_hexa(i, -nb, str);
	}
	if (nb >= len)
	{
		put_nbr_hexa(i, nb / len, str);
		put_nbr_hexa(i, nb % len, str);
	}
	else
		*i += write(1, &str[nb], 1);
}

void	put_str(int *i, char *str)
{
	while (*str)
		*i += write(1, str++, 1);
}

int	ft_printf(const char *str, ...)
{
	va_list	lst;
	int		i;

	i = 0;
	va_start(lst, str);
	while (*str)
	{
		if (*str == '%' && *(str + 1) == 's' && str++ && str++)
			put_str(&i, va_arg(lst, char *));
		if (*str == '%' && *(str + 1) == 'd' && str++ && str++)
			put_nbr_hexa(&i, va_arg(lst, int), "0123456789");
		if (*str == '%' && *(str + 1) == 'x' && str++)
			put_nbr_hexa(&i, va_arg(lst, unsigned int), "0123456789abcdef");
		else
			i += write(1, str, 1);
		str++;
	}
	return (i);
}

#include "stdio.h"

int	main(void)
{
	printf("%d\n", ft_printf("bah meme que en hexa c'est %x puis en deci c'est %d.\n sachant que j'ai une %s\n", -2147483647, -2147483647, "GROSSE BITE"));
	printf("%d\n", printf("bah meme que en hexa c'est %x puis en deci c'est %d.\n sachant que j'ai une %s\n", -2147483647, -2147483647, "GROSSE BITE"));
}
