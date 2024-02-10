/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 12:39:09 by ilyanar           #+#    #+#             */
/*   Updated: 2024/02/10 03:04:58 by ilyanar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "pipex.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/fcntl.h>
#include <unistd.h>

int	free_tab(char **tab)
{
	int	i;

	i = 0;
	if (!tab)
		return (-1);
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (0);
}

char	*join_cmd_path(char *av, char *env)
{
	int		i;
	int		k;
	char	*cmd;

	i = -1;
	k = ft_strlen(av) + ft_strlen(env) + 2;
	cmd = ft_calloc(k, sizeof(char));
	if (!cmd)
		return (NULL);
	while (env[++i])
		cmd[i] = env[i];
	cmd[i] = '/';
	k = -1;
	while (av[++k] && av[k] > 32)
		cmd[++i] = av[k];
	if ((k <= 0) || (av[ft_strlen(av) - 1] == 32))
	{
		cmd[ft_strlen(env) + 1] = 32;
		return (cmd);
	}
	return (cmd);
}

char	**ft_arg(char **tab, char *av)
{
	(void)tab;
	(void)av;
	return (NULL);
}

int	ft_count_tab(char *av)
{
	int	i;
	int	j;

	i = -1;
	j = 0;
	while (av[++i])
	{
		if (av[i] == 32)
		{
			while (av[i] == 32)
				i++;
			j++;
		}
		else if (av[i] == 39)
		{
			while (av[++i])
			{
				if (av[i] == 39 || av[i] == '\0')
					j++;
				if (av[i] == 39 || av[i] == '\0')
					break ;
			}
		}
	}
	return (j);
}

char	**ft_cmd_arg(char *av)
{
	char	**tab;
	int		j;
	int		i;
	int		k;

	i = 0;
	j = 0;
	k = -1;
	ft_printf("count : %d\n", ft_count_tab(av));
	tab = ft_calloc(ft_count_tab(av) + 1, sizeof(char **));
	while (av[i] && av[i] > 32)
		i++;
	tab[0] = ft_calloc(i + 1, sizeof(char));
	while (++k < i)
		tab[0][k] = av[k];
	if (av[i] <= 32 && av[i] != '\0')
		i++;
	k = i;
	ft_arg(tab, av);
	while (av[i])
		i++;
	tab[1] = ft_calloc((i - k) + 1, sizeof(char));
	while (k < i)
		tab[1][j++] = av[k++];
	if (j <= 0)
		tab[1] = NULL;
	return (tab);
}
