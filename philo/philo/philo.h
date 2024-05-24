/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 00:38:32 by ilyanar           #+#    #+#             */
/*   Updated: 2024/05/23 21:32:33 by ilyanar          ###   ########.fr       */
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

typedef struct s_data
{
	pthread_t		*tread;
	pthread_t		visor;
	pthread_mutex_t	mutex;
	int				philos;
	int				philo;
	size_t			t_nb_eat;
	size_t			t_die;
	size_t			t_eat;
	size_t			t_sleep;
	int				nb;
	int				i;
	bool			death;
}	t_data;

// functions

int		ft_atoi(const char *str);
int		ft_atof(const char *str);
int		ft_isdigit(int c);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);
int		check_format(char **av, int ac);
int		ft_usleep(size_t milliseconds);
size_t	get_current_time(void);

#endif
