/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 12:03:25 by ilyanar           #+#    #+#             */
/*   Updated: 2024/02/10 16:24:59 by ilyanar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "pipex.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/_types/_null.h>
#include <sys/_types/_pid_t.h>
#include <sys/fcntl.h>
#include <unistd.h>

void	ft_first_child(char *path, char **env, char **cmd, int *pipes)
{
	if (dup2(pipes[1], STDOUT_FILENO) == -1)
		ft_strerror("dup2 1", 0, NULL, NULL);
	close(pipes[0]);
	execve(path, cmd, env);
	ft_strerror("execve", 0, NULL, NULL);
}

void	ft_first_exec(t_pipe *t_pip, int *pipes, int fd)
{
	if (dup2(fd, STDIN_FILENO) == -1)
		ft_strerror("dup2 1", 0, NULL, NULL);
	close(fd);
	if (dup2(pipes[1], STDOUT_FILENO) == -1)
		ft_strerror("dup2 1", 0, NULL, NULL);
	close(pipes[0]);
	execve(t_pip->path, t_pip->arg, t_pip->env);
	ft_strerror("execve", 0, NULL, NULL);
}

void	fabien(char **env, t_pipe *t_main, int *pipes)
{
	if (pipe(pipes) == -1)
		ft_strerror("pipe", 0, NULL, t_main);
	t_main->f_pid = fork();
	if (t_main->f_pid == -1)
		ft_strerror("pid", 0, NULL, t_main);
	if (t_main->f_pid == 0 && t_main->in_fd != -1)
		ft_first_exec(t_main, pipes, t_main->in_fd);
	else if (t_main->f_pid == 0 && t_main->in_fd == 0)
		ft_first_child(t_main->path, env, t_main->arg, pipes);
	else
	{
		if (dup2(pipes[0], STDIN_FILENO) == -1)
			ft_strerror("dup2 2", 0, NULL, t_main);
		close(pipes[1]);
		waitpid(t_main->f_pid, NULL, 0);
	}
}

void	pipex(char **av, char **envp, int fd)
{
	t_pipe	t_main;

	init_path(&t_main, envp);
	t_main.in_fd = fd;
	t_main.out_fd = STDOUT_FILENO;
	av += 2;
	for (int d = 0; t_main.env[d]; d++)
		ft_printf("env[%d] : %s\n", d, t_main.env[d]);
	while (*av)
	{
		path_command(*av, &t_main);
		ft_printf("\npath : %s\n", t_main.path);
		found_cmd_alone(&t_main, *av);
		ft_printf("\ncmd_alone : %s\n\n", t_main.cmd_alone);
		parse_arg(&t_main, *av);
		if (t_main.arg)
			for (int d = 0; t_main.env[d]; d++)
				ft_printf("arg[%d] : %s\n", d, t_main.arg[d]);
//		fabien(envp, &t_main, t_main.pipes1);
//		fabien(envp, &t_main, t_main.pipes2);
		ft_free_char(&t_main, 0);
		av++;
	}
	return (ft_free_char(&t_main, 1));
}

int	main(int ac, char **av, char **envp)
{
	int		fd;

	if (((ac < 5) || (access(av[1], R_OK) != 0)))
	{
		if (ac < 5)
			ft_printf("less arg than 5");
		else
			ft_printf("'%s' dosen't exist\n", av[1]);
		exit(EXIT_FAILURE);
	}
	else
	{
		fd = open(av[1], O_RDONLY);
		pipex(av, envp, fd);
		close(fd);
	}
	return (0);
}
