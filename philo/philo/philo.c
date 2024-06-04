/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 16:02:48 by ilyanar           #+#    #+#             */
/*   Updated: 2024/06/04 13:37:15 by fclivaz          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <pthread.h>
#include <stdio.h>

void	death_checker(t_data *data)
{
	(void)data;
}

void	philo_eat(t_philo *philo)
{
	t_data *data;

	data = philo->data;
	pthread_mutex_lock(&(philo->fork));
	print_act(data, data->philo_nb, "has taken a fork");
	pthread_mutex_lock((philo->r_fork));
	print_act(data, data->philo_nb, "has taken a fork");
	pthread_mutex_lock(&(data->value));
	print_act(data, data->philo_nb, "is eating");
	philo->t_last_meal = timestamp();
	pthread_mutex_unlock(&(data->value));
	ft_usleep(data->t_eat, data);
	pthread_mutex_unlock(&(philo->fork));
	pthread_mutex_unlock((philo->r_fork));
}

void	*philo_routine(void *arg)
{
	t_philo	*phil;
	t_data	*data;

	phil = arg;
	data = phil->data;
	if (data->philo_nb % 2)
		ft_usleep(15000, data);
	pthread_mutex_unlock(&data->value);
	while(!data->all_eat)
	{
		philo_eat(phil);
		if (data->all_eat)
			break ;
		print_act(data, data->philo_nb, "is sleeping");
		ft_usleep(data->t_sleep, data);
		print_act(data, data->philo_nb, "is thinking");
	}
	return (NULL);
}

int	hypervisor(t_data *data)
{
	int	i;

	i = -1;
	data->first_time = timestamp();
	while (++i < data->philo_nb)
	{
		if (pthread_create(&data->pthreads[i], \
			NULL, philo_routine, (void *)&data) && printf("error of thread\n"))
			return (0);
		data->philos->t_last_meal = timestamp();
	}
	death_checker(data);
	wait_all(data);
	return (1);
}

int	main(int ac, char **av)
{
	t_data			data;

	if (!check_format(av, ac) || !initialize_philo(&data, av))
		return (0);
	if (!hypervisor(&data))
		return (1);
	destroy_mutex(&data);
}
