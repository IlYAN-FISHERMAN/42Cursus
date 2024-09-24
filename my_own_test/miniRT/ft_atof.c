#include <math.h>
#include <stdio.h>
#include "../../miniRT-42/libs/betterft/betterft.h"

float	ft_atof(char *str)
{
	float	nb;
	int		i;
	int		j;
	int		sign;

	i = -1;
	nb = 0;
	j = 0;
	sign = 1;
	if (str[0] == '-')
	{
		sign = -1;
		i++;
	}
	while (str[++i])
	{
		if (str[i] == '.')
		{
			while (str[++i] && ++j)
				nb = (nb * (float)pow(10, j) + (str[i] - 48)) / pow(10, j);
			return (nb * sign);
		}
		nb = nb * 10 + (str[i] - 48);
	}
	return (nb * sign);
}

int	only_digit(char *str)
{
	int		nb;
	char	*tmp;

	nb = ft_atoi(str);
	tmp = ft_itoa(nb);
	if (!tmp)
		return (0);
	if (ft_strcmp(str, tmp))
	{
		free(tmp);
		return (0);
	}
	free(tmp);
	return (1);
}

int	only_float(char *str)
{
	int		i;

	i = -1;
	if (!str || str[0] == '.' || !ft_strchr(str, '.'))
		return (0);
	if (str[0] == '-' || str[0] == '+')
		i++;
	while (str[++i] && str[i] != '.')
		if (!ft_isdigit(str[i]) || !str[i + 1])
			return (0);
	while (str[++i])
		if (!ft_isdigit(str[i]))
			return (0);
	return (1);
}

int	only_digit_xyz(char *split)
{
	int		j;
	char	**str;

	if (!ft_strchr(split, ','))
		return (0);
	j = -1;
	str = ft_split(split, ',');
	if (!str)
		return (0);
	while (str[++j])
	{
		if (!only_digit(str[j]) || j >= 3)
		{
			ft_free_tab(str);
			return (0);
		}
	}
	ft_free_tab(str);
	if (j <= 2)
		return (0);
	return (1);
}

int	only_float_xyz(char *split)
{
	int		j;
	char	**str;

	j = -1;
	if (!ft_strchr(split, ','))
		return (0);
	str = ft_split(split, ',');
	if (!str)
		return (0);
	while (str[++j])
	{
		if (!only_float(str[j]))
		{
			ft_free_tab(str);
			return (0);
		}
	}
	if (j <= 2 || j > 3)
		return (0);
	ft_free_tab(str);
	return (1);
}

int	ft_atof_xyz(float *x, float *y, float *z, char **str)
{
	if (!str)
		return (0);
	*x = ft_atof(str[0]);
	*y = ft_atof(str[1]);
	*z = ft_atof(str[2]);
	ft_free_tab(str);
	return (1);
}

int	ft_atoi_xyz(int *x, int *y, int *z, char **str)
{
	if (!str)
		return (0);
	*x = ft_atoi(str[0]);
	*y = ft_atoi(str[1]);
	*z = ft_atoi(str[2]);
	ft_free_tab(str);
	return (1);
}

int	main(int ac, char **av)
{
	int		i;

	i = 0;
	(void)ac;
	while (av[++i])
	{
		if (only_float_xyz(av[i]))
			printf("\033[0;32m\"%s\" it's a xyz float\033\n", av[i]);
		else if (only_digit_xyz(av[i]))
			printf("\033[0;33m\"%s\" it's a xyz int\033\n", av[i]);
		else
			printf("\033[0;31m\"%s\" it's not xyz float or int\033[0m\n", av[i]);
	}
}
