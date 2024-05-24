/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 16:02:48 by ilyanar           #+#    #+#             */
/*   Updated: 2024/05/23 21:37:00 by ilyanar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <pthread.h>

void	wait_all(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->philos)
	{
		if (pthread_join(data->tread[i], NULL)
			&& printf("error join thread\n"))
			return ;
		i++;
	}
}

void	*philosophers(void	*arg)
{
	t_data	*data;

	data = (t_data *)arg;
	pthread_mutex_lock(&data->mutex);
	data->philo++;
	printf("%d is taking a fork\n", data->philo);
	printf("%d is taking a fork\n", data->philo);
	printf ("%d is eating\n", data->philo);
	ft_usleep(data->t_eat);
	printf("%zu %d is sleeping\n", data->t_sleep / 1000, data->philo);
	ft_usleep(data->t_sleep);
	pthread_mutex_unlock(&data->mutex);
	return (NULL);
}

void	*hypervisor(void *arg)
{
	t_data	*data;

	data = (t_data *)arg;
	while (data->i < data->philos)
	{
		if (pthread_create(&data->tread[data->i], \
			NULL, philosophers, (void *)&data) && printf("error of thread\n"))
			return (NULL);
		data->i++;
	}
	wait_all(data);
	return (NULL);
}

void	initialize_philo(t_data *data, char **av)
{
	ft_bzero(data, sizeof(t_data));
	data->t_sleep = ft_atoi(av[4]);
	data->t_die = ft_atoi(av[2]);
	data->philos = ft_atoi(av[1]);
	data->t_eat = ft_atoi(av[3]);
	if (av[5])
		data->t_nb_eat = ft_atoi(av[5]);
	else
		data->t_nb_eat = 1;
	data->tread = ft_calloc(data->philos, sizeof(pthread_t));
	pthread_mutex_init(&data->mutex, NULL);
}

int	main(int ac, char **av)
{
	t_data			data;

	if (!check_format(av, ac))
		return (0);
	initialize_philo(&data, av);
	if (pthread_create(&data.visor, \
		NULL, &hypervisor, (void *)&data) && printf("error of thread\n"))
		return (1);
	if (pthread_join(data.visor, NULL)
		&& printf("error join thread\n"))
		return (0);
	pthread_mutex_destroy(&data.mutex);
}
