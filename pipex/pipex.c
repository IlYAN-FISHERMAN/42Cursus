/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 12:03:25 by ilyanar           #+#    #+#             */
/*   Updated: 2024/01/24 14:36:14 by ilyanar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <stdio.h>
#include <stdlib.h>
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
	path = path_line(env, "PATH\0");
	tab = ft_split(path, ':');
	if (tab)
		while (tab[++i])
			ft_printf("\033[31m%s\033[0m\n", tab[i]);
	if (!tab)
		return (0);
	return (1);
}

int	main(int ac, char **av, char *envp[])
{
	int		pid;
	char	*arg[] = {av[2], NULL, NULL};
	char	**tab;

	tab = 0;
	if (ac < 5)
		exit(EXIT_FAILURE);
	pid = fork();
	if (pid == -1)
	{
		perror("\033[31mError\033[0m");
		exit(EXIT_FAILURE);
	}
	if (pid == 0)
	{
		if (access(av[1], R_OK) != 0)
		{
			perror("\033[31mError access\033[0m");
			exit(EXIT_FAILURE);
		}
		if (check_path(tab, envp) == 0)
		{
			perror("\033[31mError path\033[0m");
			exit(EXIT_FAILURE);
		}
		execve("/usr/bin/ls", arg, NULL);
		perror("\033[31mError child\033[0m");
		exit(EXIT_FAILURE);
	}
	else if (waitpid(pid, NULL, 0))
	{
		open("fdp.txt", O_CREAT | O_WRONLY, 0644);
		ft_printf("end\n");
	}
	return (0);
}
