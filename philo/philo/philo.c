/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 16:02:48 by ilyanar           #+#    #+#             */
/*   Updated: 2024/05/24 23:25:42 by ilyanar          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <pthread.h>
#include <stdio.h>

int	wait_all(t_data *data)
{
	static int	i;
	
	i = -1;
	while (++i < data->philo_nb)
	{
		if (pthread_join(data->pthreads[i], NULL))
			return (0);
	}
	return (1);
}

void	init_mutexx(t_data *data)
{
	int		i;
	t_philo	*tmp;

	i = -1;
	while (++i < data->philo_nb)
	{
		tmp = &data->philos[i];
		pthread_mutex_init(&tmp->fork, NULL);
	}
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
		data->t_nb_eat = 0;
	if (data->t_nb_eat < 0)
		return (0);
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
	pthread_mutex_destroy(&data->print);
	pthread_mutex_destroy(&data->dead);
	free(data->philos);
	free(data->pthreads);
}

int	init_philo(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->philo_nb)
		if (pthread_create(&data.visor, \
			NULL, &hypervisor, (void *)&data) && printf("error of thread\n"))
			return (1);
}

void	*hypervisor(void *arg)
{
	t_data	*data;
	int		i;

	i = -1;
	data = (t_data *)arg;
	if (!init_philo(data))
		return (NULL);
	while (true)
	{
	}
	return (NULL);
}

int	main(int ac, char **av)
{
	t_data			data;

	if (!check_format(av, ac) || !initialize_philo(&data, av))
		return (0);
	if (pthread_create(&data.visor, \
		NULL, &hypervisor, (void *)&data) && printf("error of thread\n"))
		return (1);
	if (pthread_join(data.visor, NULL)
		&& printf("error join thread\n"))
		return (0);
	destroy_mutex(&data);
}
