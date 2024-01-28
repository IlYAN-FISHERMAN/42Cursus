/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 12:03:25 by ilyanar           #+#    #+#             */
/*   Updated: 2024/01/26 19:53:46 by ilyanar          ###   ########.fr       */
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
	if (tab)
		while (tab[++i])
			ft_printf("\033[38;5;208m%s\033[0m\n", tab[i]);
	if (!tab)
		return (0);
	return (1);
}

int	check_command(char **tab, char *arg)
{
}

int	pipex(char **av, char **envp, int ac)
{
	int		i;
	int		pid;
	char	**tab;
	char	**arg;

	i = 0;
	tab = 0;
	arg = 0;
	if (check_path(tab, envp) == 0)
	{
		perror("\033[31mError path\033[0m");
		exit(EXIT_FAILURE);
	}
	pid = fork();
	if (pid == -1)
	{
		perror("\033[31mError\033[0m");
		exit(EXIT_FAILURE);
	}
	if (pid == 0)
	{
		execve("/bin/ls", arg, envp);
		perror("\033[31mError child\033[0m");
		exit(EXIT_FAILURE);
	}
	else if (waitpid(pid, NULL, 0))
	{
		open(av[ac], O_CREAT | O_TRUNC | O_WRONLY, 0644);
		ft_printf("end\n");
	}
	ft_free_tab(tab);
	return (0);
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
}
