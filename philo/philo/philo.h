/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 00:38:32 by ilyanar           #+#    #+#             */
/*   Updated: 2024/05/24 21:39:15 by ilyanar          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h> 
# include <stdbool.h>
# include <sys/_pthread/_pthread_mutex_t.h>
# include <sys/_types/_timeval.h>
# include <sys/time.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_philo
{
	pthread_mutex_t	fork;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*r_fork;
}	t_philo;

typedef struct s_data
{
	pthread_t		*pthreads;
	t_philo			*philos;
	pthread_t		visor;
	pthread_mutex_t	print;
	pthread_mutex_t	dead;
	int				philo_nb;
	size_t			t_nb_eat;
	size_t			t_die;
	size_t			t_eat;
	size_t			t_sleep;
	int				nb;
	int				i;
	bool			death;
	int				time;
}	t_data;

// functions

long	ft_atoi(const char *str);
int		ft_isdigit(int c);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);
int		check_format(char **av, int ac);
void	ft_usleep(long time_in_ms);
long	get_timestamp(void);
long	actual_time(void);

#endif
