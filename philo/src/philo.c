/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 16:02:48 by ilyanar           #+#    #+#             */
/*   Updated: 2024/05/21 18:06:35 by ilyanar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*print_me(void *arg)
{
	t_data	*data;

	data = (t_data *)arg;
	pthread_mutex_lock(&data->mutex);
	data->nb = random() % 500;
	printf("i'm the philo[%d]: i print the %d number\n", data->i + 1, data->nb);
	usleep(data->t_sleep);
	pthread_mutex_unlock(&data->mutex);
	return (NULL);
}

int	main(int ac, char **av)
{
	t_data			data;

	if (!check_format(av, ac))
		return (0);
	ft_bzero(&data, sizeof(t_data));
	data.t_sleep = ft_atof(av[4]);
	data.t_die = ft_atof(av[2]);
	data.philos = ft_atoi(av[1]);
	data.t_eat = ft_atoi(av[3]);
	if (av[5])
		data.t_nb_eat = ft_atoi(av[5]);
	data.tread = ft_calloc(data.philos, sizeof(pthread_t));
	pthread_mutex_init(&data.mutex, NULL);
	while (data.i < data.philos)
	{
		if (pthread_create(&data.tread[data.i], \
			NULL, print_me, (void *)&data) != 0 && printf("error de thread\n"))
			return (1);
		if (pthread_join(data.tread[data.i], NULL)
			&& printf("error de join thread\n"))
			return (1);
		data.i++;
	}
	return (data.nb);
}
