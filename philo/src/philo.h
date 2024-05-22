/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 00:38:32 by ilyanar           #+#    #+#             */
/*   Updated: 2024/05/21 17:50:40 by ilyanar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h> 
# include <sys/_pthread/_pthread_mutex_t.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_data
{
	pthread_t		*tread;
	pthread_mutex_t	mutex;
	int				philos;
	int				t_nb_eat;
	float			t_die;
	float			t_eat;
	float			t_sleep;
	int				nb;
	int				i;
}	t_data;

// functions

int		ft_atoi(const char *str);
int		ft_atof(const char *str);
int		ft_isdigit(int c);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);
int		check_format(char **av, int ac);

#endif
