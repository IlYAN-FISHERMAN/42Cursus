/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 12:03:25 by ilyanar           #+#    #+#             */
/*   Updated: 2024/01/30 08:44:02 by ilyanar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/fcntl.h>
#include <sys/unistd.h>
#include <sys/wait.h>
#include <unistd.h>

char	*path_line(char **env, char *path)
{
	int	i;
	int	j;

	i = -1;
	j = 0;
	while (*env[++i] != '\0')
	{
		while (env[i][j] == path[j])
		{
			j++;
			if (path[j] == '\0')
				return (env[i]);
		}
		j = 0;
	}
	return (0);
}

int	check_path(char **tab, char **env)
{
	char	*path;
	int		i;

	i = -1;
	path = path_line(env, "PATH");
	tab = ft_split(path, ':');
	if (!tab)
	{
		ft_free_tab(tab);
		return (0);
	}
	path = ft_strdup(ft_strchr(tab[0], '=') + 1);
	free(tab[0]);
	tab[0] = path;
	while (++i, tab[i])
		ft_printf("%s\n", tab[i]);
	return (1);
}

int	true_command(char **tab)
{
	return (0);
}

int	exec_command(void)
{
	int	pid;
	if (waitpid(pid, NULL, 0))
	{
		open(av[ac], O_CREAT | O_TRUNC | O_WRONLY, 0644);
		ft_printf("end\n");
	}
	return (0);
}

int	pipex(char **av, char **envp, int ac)
{
	int		i;
	char	**tab;
	char	**arg;

	tab = 0;
	arg = 0;
	i = -1;
	while (++i < ac)
	{
		if (check_path(tab, envp) == 0)
		{
			perror("\033[31mError path\033[0m");
			exit(EXIT_FAILURE);
		}
		if (true_command(tab) == 1)
			exec_command();
	}
	return (ft_free_tab(tab) + 1);
}

int	main(int ac, char **av, char **envp)
{
	if (((ac < 5) || (access(av[1], R_OK) != 0)))
	{
		strerror(-1);
		exit(EXIT_FAILURE);
	}
	else
		pipex(av, envp, ac);
	ft_printf("test\n");
}
