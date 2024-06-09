/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 16:02:48 by ilyanar           #+#    #+#             */
/*   Updated: 2024/06/09 12:28:45 by ilyanar          ###   LAUSANNE.ch       */
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
		if (pthread_join(data->pthreads[i], NULL))
			return (0);
	return (1);
}

void	philo_eat(t_philo *philo)
{
	t_data	*data;

	data = philo->data;
	pthread_mutex_lock(&(philo->fork));
	pthread_mutex_lock((philo->r_fork));
	print_act(data, philo->id, "has taken a fork");
	print_act(data, philo->id, "has taken a fork");
	print_act(data, philo->id, "is eating");
	pthread_mutex_lock(&(data->value));
	philo->t_last_meal = timestamp();
	pthread_mutex_unlock(&(data->value));
	ft_usleep(data->t_eat, data);
	pthread_mutex_lock(&philo->l_meal);
	(philo->nb_eat)++;
	pthread_mutex_unlock(&philo->l_meal);
	pthread_mutex_unlock(&(philo->fork));
	pthread_mutex_unlock((philo->r_fork));
}

void	*philo_routine(void *arg)
{
	t_philo	*phil;
	t_data	*data;

	phil = arg;
	data = phil->data;
	if ((phil->id % 2))
		ft_usleep(data->t_sleep, data);
	while (!check_death(data))
	{
		philo_eat(phil);
		if (check_eat(data))
			break ;
		pthread_mutex_unlock(&data->all_et);
		print_act(data, phil->id, "is sleeping");
		ft_usleep(data->t_sleep, data);
		print_act(data, phil->id, "is thinking");
		if ((phil->id % 2))
			ft_usleep(4, data);
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
			NULL, philo_routine, (void *)&data->philos[i])
			&& printf("error of thread\n"))
			return (0);
		pthread_mutex_lock(&(data->value));
		data->philos[i].t_last_meal = timestamp();
		pthread_mutex_unlock(&(data->value));
	}
	death_checker(data, data->philos);
	wait_all(data);
	return (1);
}

int	main(int ac, char **av)
{
	t_data	data;

	if (!check_format(av, ac) || !initialize_philo(&data, av))
		return (0);
	if (!hypervisor(&data))
		return (1);
	destroy_mutex(&data);
}
