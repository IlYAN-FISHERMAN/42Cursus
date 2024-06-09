/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 20:11:15 by ilyanar           #+#    #+#             */
/*   Updated: 2024/06/09 11:41:49 by ilyanar          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_nbr_format(char **av)
{
	if ((ft_atoi(av[1]) < 1 || ft_atoi(av[1]) > 200)
		&& printf("philo: Error number of philo. (1 to 200)\n"))
		return (0);
	else if ((ft_atoi(av[1]) == 1)
		&& printf("0 1 has taken a fork\n%ld 1 died\n", ft_atoi(av[2])))
		return (0);
	if ((ft_atoi(av[2]) < 0 || ft_atoi(av[3]) < 0
			|| ft_atoi(av[4]) < 0)
		&& printf("philo: only positif number accepted\n"))
		return (0);
	if (av[5] && ft_atoi(av[5]) <= 0)
		return (0);
	return (1);
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
				("philo: bad format: \"%s\", only positif numbers accepted\n"\
				, av[j]))
				return (0);
	}
	if (!check_nbr_format(av))
		return (0);
	return (1);
}
