/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclivaz <fclivaz@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 19:26:59 by fclivaz           #+#    #+#             */
/*   Updated: 2024/06/05 02:04:59 by fclivaz          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_forks(t_data *data)
{
	int		i;
	t_philo	*tmp1;
	t_philo	*tmp2;

	i = -1;
	while (++i < data->philo_nb)
	{
		tmp1 = &data->philos[i];
		if (i - 1 >= 0)
		{
			tmp2 = &data->philos[i - 1];
			tmp1->l_fork = &tmp2->fork;
		}
		if (i + 1 < data->philo_nb)
		{
			tmp2 = &data->philos[i + 1];
			tmp1->r_fork = &tmp2->fork;
		}
	}
	if (data->philo_nb > 1)
		data->philos[0].l_fork = &data->philos[data->philo_nb - 1].fork;
	if (data->philo_nb > 1)
		data->philos[data->philo_nb - 1].r_fork = &data->philos[0].fork;
}

void	init_mutexx(t_data *data)
{
	int		i;
	t_philo	*tmp;

	i = -1;
	tmp = NULL;
	while (++i < data->philo_nb)
	{
		tmp = &data->philos[i];
		tmp->id = i;
		pthread_mutex_init(&tmp->fork, NULL);
		tmp->data = data;
	}
	init_forks(data);
	pthread_mutex_init(&data->value, NULL);
	pthread_mutex_init(&data->print, NULL);
	pthread_mutex_init(&data->dead, NULL);
}

int	initialize_philo(t_data *data, char **av)
{
	ft_bzero(data, sizeof(t_data));
	data->philo_nb = ft_atoi(av[1]);
	data->t_die = ft_atoi(av[2]);
	data->t_eat = ft_atoi(av[3]);
	data->t_sleep = ft_atoi(av[4]);
	if (av[5])
		data->t_nb_eat = ft_atoi(av[5]);
	else
		data->t_nb_eat = -1;
	data->pthreads = ft_calloc(data->philo_nb, sizeof(pthread_t));
	if (!data->pthreads)
		return (0);
	data->philos = ft_calloc(data->philo_nb, sizeof(t_philo));
	if (!data->philos)
		return (0);
	init_mutexx(data);
	return (1);
}

void	destroy_mutex(t_data *data)
{
	int		i;
	t_philo	*tmp;

	i = -1;
	while (++i < data->philo_nb)
	{
		tmp = &data->philos[i];
		pthread_mutex_destroy(&tmp->fork);
	}
	pthread_mutex_destroy(&data->value);
	pthread_mutex_destroy(&data->print);
	pthread_mutex_destroy(&data->dead);
	free(data->philos);
	free(data->pthreads);
}
