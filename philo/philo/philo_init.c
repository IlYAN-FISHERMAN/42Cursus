/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclivaz <fclivaz@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 19:26:59 by fclivaz           #+#    #+#             */
/*   Updated: 2024/06/04 13:55:04 by fclivaz          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_mutexx(t_data *data)
{
	int		i;
	t_philo	*tmp;

	i = -1;
	tmp = NULL;
	while (++i < data->philo_nb)
	{
		tmp = &data->philos[i];
		pthread_mutex_init(&tmp->fork, NULL);
		tmp->r_fork = NULL;
		tmp->l_fork = NULL;
		tmp->data = data;
	}
	i = 0;
	while (i < data->philo_nb)
	{
		if (i + 1 < data->philo_nb)
		{
			printf("philo_fork: %p\n", &tmp[i].fork);
			printf("philo_l_fork: %p\n", tmp[i].l_fork);
			printf("philo_r_fork: %p\n\n", tmp[i].r_fork);
		}
		i++;
	}
	// for (int d = 0; d < data->philo_nb; d++)
	// {
	// 	printf("philo_fork: %p\n", &tmp[d].fork);
	// 	printf("philo_l_fork: %p\n", tmp[d].l_fork);
	// 	printf("philo_r_fork: %p\n\n", tmp[d].r_fork);
	// }
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
