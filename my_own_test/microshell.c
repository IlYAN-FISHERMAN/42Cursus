/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   microshell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 23:10:02 by ilyanar           #+#    #+#             */
/*   Updated: 2024/06/22 00:59:59 by ilyanar          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int	ft_strlen(char *str)
{
	int i = 0;

	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

void	get_info(char **av, int *is_pipe, int *j, int *i)
{
	while (av[*j] && strcmp(av[*j], "|") && strcmp(av[*j], ";"))
		(*j)++;
	if (av[*j] && !strcmp(av[*j], "|"))
	{
		if (av[(*j) + 1])
			*is_pipe = 1;
		av[*j] = NULL;
		(*j)++;
	}
	else if (av[*j] && !strcmp(av[*j], ";"))
	{
		*is_pipe = 0;
		while (av[*j] && !strcmp(av[*j], ";"))
		{
			av[*j] = NULL;
			(*j)++;
		}
		if (!av[*i])
		{
			*i = *j;
			get_info(av, is_pipe, j, i);
		}
	}
	else
		*is_pipe = 0;
}

void	child(int *pip1, int *pip2, char **av, char **env, int is_pip, int pre_pip, int i)
{
	int pid = 0;

	pid = fork();
	if (!pid)
	{
		if (pre_pip && (dup2(pip2[0], STDIN_FILENO) == -1 || close(pip2[0]) == -1))
		{
			write(2, "error: fatal\n", 13);
			exit(127);
		}
		if (is_pip && (dup2(pip1[1], STDOUT_FILENO) == -1 || close(pip1[1]), close(pip1[0])))
		{
			write(2, "error: fatal\n", 13);
			exit(127);
		}
		execve(av[i], av + i, env);
		write(2, "error: cannot execute ", 22);
		write(2, av[i], ft_strlen(av[i]));
		write(2, "\n", 1);
		exit(127);
	}
	else
	{
		waitpid(pid, 0, 0);
		close(pip1[1]);
		if (pre_pip)
			close(pip2[0]);
	}
}

int	main(int ac, char **av, char **env)
{
	int	is_pip = 0;
	int	pre_pip = 0;
	int pip1[2];
	int	pip2[0];
	int i = 1;
	int	j = 1;

	if (ac <= 1)
		return (1);
	if (!strcmp(av[1], "cd"))
	{
		if (ac != 3)
		{
			write(2, "error: cd: bad arguments\n", 25);
			i = 3;
			j = 3;
		}
		else if (chdir(av[2]) == -1 && write(2, "error: cd: cannot change directory to ", 38) && write(2, av[2], ft_strlen(av[2])))
			return (1);
	}
	while (j < ac)
	{
		pipe(pip1);
		get_info(av, &is_pip, &j, &i);
		if (i == ac)
			break ;
		child(pip1, pip2, av, env, is_pip, pre_pip, i);
		if (is_pip)
			pre_pip = 1;
		*pip2 = *pip1;
		while (i < j)
			i++;
	}
}
