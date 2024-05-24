/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 16:08:54 by ilyanar           #+#    #+#             */
/*   Updated: 2024/05/24 23:29:31 by ilyanar          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <sys/_types/_u_int64_t.h>

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

void	ft_bzero(void *s, size_t n)
{
	size_t		i;
	char		*tab;

	i = 0;
	tab = (char *)s;
	while (i != n)
	{
		tab[i] = '\0';
		i++;
	}
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*tab;

	tab = malloc(count * size);
	if (!tab)
		return (NULL);
	ft_bzero(tab, count * size);
	return (tab);
}

long	ft_atoi(const char *str)
{
	long	i;
	long	nb;

	nb = 0;
	i = 1;
	while ((*str >= 9 && *str <= 13) || (*str == 32))
		str++;
	if (*str == '-')
	{
		i = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		nb = nb * 10 + (*str - 48);
		str++;
	}
	return (nb * i);
}

int	check_format(char **av, int ac)
{
	int	i;
	int	j;

	j = 0;
	if ((ac < 5 || ac > 6) && printf("philo: require 4 or 5 different numbers\
		\n\"number_of_philosophers\"\n\"time_to_die\"\n\"time_to_eat\"\
		\n\"time_to_sleep\"\
		\n\"number_of_times_each_philosopher_must_eat\"\n"))
		return (0);
	while (av[++j])
	{
		i = -1;
		while (av[j][++i])
			if (!ft_isdigit(av[j][i])
				&& printf \
				("philo: bad format \"%s\", only numbers are accepted\n"\
				, av[j]))
				return (0);
	}
	return (1);
}

long	get_timestamp(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

void	ft_usleep(long time_in_ms)
{
	long int		time;

	time = get_timestamp();
	while (get_timestamp() - time < time_in_ms)
		usleep(time_in_ms / 10);
}

long	actual_time(void)
{
	long int			time;
	struct timeval		current_time;

	time = 0;
	gettimeofday(&current_time, NULL);
	time = (current_time.tv_sec * 1000) + (current_time.tv_usec / 1000);
	return (time);
}
