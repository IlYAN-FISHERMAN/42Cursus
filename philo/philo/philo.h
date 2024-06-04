/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 00:38:32 by ilyanar           #+#    #+#             */
/*   Updated: 2024/06/03 15:05:12 by fclivaz          ###   LAUSANNE.ch       */
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
	long 			t_last_meal;
	pthread_mutex_t	fork;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*r_fork;
	struct s_data *data;
}	t_philo;

typedef struct s_data
{
	pthread_t		*pthreads;
	t_philo			*philos;
	pthread_t		visor;
	pthread_mutex_t	value;
	pthread_mutex_t	print;
	pthread_mutex_t	dead;
	int				philo_nb;
	long			t_nb_eat;
	size_t			t_die;
	size_t			t_eat;
	size_t			t_sleep;
	int				nb;
	int				i;
	bool			death;
	long long		first_time;
	int				time;
	bool			all_eat;
}	t_data;

// functions

long	ft_atoi(const char *str);
int		ft_isdigit(int c);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);
int		check_format(char **av, int ac);
void	ft_usleep(long time_in_ms, t_data *data);
long	timestamp(void);
long	actual_time(void);
void	init_mutexx(t_data *data);
int		initialize_philo(t_data *data, char **av);
void	destroy_mutex(t_data *data);
int		init_philo(t_data *data);
void	*philo_routine(void *arg);
int		wait_all(t_data *data);
void	print_act(t_data *print, int id, char *string);

#endif
