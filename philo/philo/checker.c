/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 20:07:39 by ilyanar           #+#    #+#             */
/*   Updated: 2024/06/09 12:29:49 by ilyanar          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_eat(t_data *data)
{
	pthread_mutex_lock(&data->all_et);
	if (!data->all_eat && !pthread_mutex_unlock(&data->all_et))
		return (0);
	pthread_mutex_unlock(&data->all_et);
	return (1);
}

int	check_death(t_data *data)
{
	pthread_mutex_lock(&data->dead);
	if (!data->death && !pthread_mutex_unlock(&data->dead))
		return (0);
	pthread_mutex_unlock(&data->dead);
	return (1);
}

int	is_dead(t_data *data, t_philo *phil)
{
	int	i;

	i = 0;
	if (check_death(data))
		return (1);
	i = 0;
	pthread_mutex_lock(&phil->l_meal);
	while (data->t_nb_eat != -1 && i < data->philo_nb
		&& phil->nb_eat >= data->t_nb_eat)
		i++;
	pthread_mutex_unlock(&phil->l_meal);
	if (i == data->philo_nb)
	{
		pthread_mutex_lock(&data->all_et);
		data->all_eat = true;
		pthread_mutex_unlock(&data->all_et);
	}
	return (0);
}

void	death_checker(t_data *data, t_philo *phil)
{
	int		i;

	while (!check_eat(data))
	{
		i = -1;
		while (++i < data->philo_nb && !check_death(data))
		{
			pthread_mutex_lock(&data->did_he_eat);
			pthread_mutex_lock(&(data->value));
			if (timestamp() - phil->t_last_meal > data->t_die)
			{
				print_act(data, i, "died");
				pthread_mutex_lock(&(data->dead));
				data->death = true;
				pthread_mutex_unlock(&(data->dead));
			}
			pthread_mutex_unlock(&(data->value));
			pthread_mutex_unlock(&data->did_he_eat);
			ft_usleep(4, data);
		}
		if (is_dead(data, phil))
			break ;
	}
}
