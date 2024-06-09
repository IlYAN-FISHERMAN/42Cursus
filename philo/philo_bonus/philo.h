/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 00:38:32 by ilyanar           #+#    #+#             */
/*   Updated: 2024/06/08 22:24:08 by ilyanar          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <semaphore.h>
# include <stdio.h> 
# include <stdbool.h>
# include <sys/_pthread/_pthread_mutex_t.h>
# include <sys/_types/_timeval.h>
# include <sys/time.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_philo
{
	long			t_last_meal;
	int				id;
	int				nb_eat;
	pthread_mutex_t	fork;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	l_meal;
	struct s_data	*data;
}	t_philo;

typedef struct s_data
{
	int				philo_nb;
	int				nb;
	int				i;
	int				time;
	bool			death;
	bool			all_eat;
	long			t_die;
	size_t			t_eat;
	size_t			t_sleep;
	long			t_nb_eat;
	long long		first_time;
	pthread_mutex_t	value;
	pthread_mutex_t	print;
	pthread_mutex_t	dead;
	pthread_mutex_t	did_he_eat;
	pthread_mutex_t	all_et;
	pthread_t		visor;
	t_philo			*philos;
	pthread_t		*pthreads;
}	t_data;

// functions

int		wait_all(t_data *data);
void	philo_eat(t_philo *philo);
void	*philo_routine(void *arg);
int		hypervisor(t_data *data);
int		check_eat(t_data *data);
int		check_death(t_data *data);
int		is_dead(t_data *data, t_philo *phil);
void	it_is_dead(t_data *data, t_philo *phil);
int		check_nbr_format(char **av);
int		check_format(char **av, int ac);
void	init_forks(t_data *data);
void	init_mutexx(t_data *data);
int		initialize_philo(t_data *data, char **av);
void	destroy_mutex(t_data *data);
int		ft_isdigit(int c);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);
long	ft_atoi(const char *str);
void	print_act(t_data *print, int id, char *string);
long	timestamp(void);
void	ft_usleep(long time_in_ms, t_data *data);
long	actual_time(void);

#endif
