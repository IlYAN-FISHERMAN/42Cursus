/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 12:03:25 by ilyanar           #+#    #+#             */
/*   Updated: 2024/02/18 00:10:58 by ilyanar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "pipex.h"
#include <stdlib.h>
#include <sys/_types/_null.h>
#include <sys/_types/_pid_t.h>
#include <sys/fcntl.h>
#include <unistd.h>

int	wait_process(t_list *pid)
{
	int	status;

	while (pid)
	{
		waitpid(*(pid_t *)pid->content, &status, 0);
		pid = pid->next;
	}
	if (WIFEXITED(status))
		status = WEXITSTATUS(status);
	else
		status = 0;
	return (status);
}

void	ft_maria(char **env, t_pipe *t_main, t_list *pid)
{
	pid_t	pidt;

	pidt = fork();
	if (pidt == 0)
	{
		dup2(t_main->pipes1[1], STDOUT_FILENO);
		close(t_main->pipes1[0]);
		close(t_main->pipes1[1]);
		execve(t_main->path, t_main->args, env);
		ft_strerror("Execve error", 0, NULL, t_main);
	}
	else
	{
		ft_lstadd_back(&pid, ft_lstnew(&pidt));
		dup2(t_main->pipes1[0], t_main->pipes2[1]);
		close(t_main->pipes1[0]);
		close(t_main->pipes1[1]);
	}
}

void	ft_fabien(char **env, t_pipe *t_main, t_list *pid)
{
	pid_t	pidt;

	pidt = fork();
	if (pidt == 0)
	{
		if (t_main->last == 1)
			dup2(t_main->out_fd, STDOUT_FILENO);
		else
			dup2(t_main->pipes2[1], STDOUT_FILENO);
		close(t_main->pipes2[0]);
		close(t_main->pipes2[1]);
		execve(t_main->path, t_main->args, env);
		ft_strerror("Execve error", 0, NULL, t_main);
	}
	else
	{
		ft_lstadd_back(&pid, ft_lstnew(&pidt));
		if (t_main->last == 1)
			dup2(t_main->pipes2[1], STDIN_FILENO);
		else
			dup2(t_main->pipes2[0], STDIN_FILENO);
		close(t_main->pipes2[1]);
	}
}

int	pipex(char **av, char **envp, t_pipe *t_main)
{
	t_list	*pid;

	pid = NULL;
	while (*av && *(av + 1) != NULL)
	{
		path_command(*av, t_main);
		found_cmd_alone(t_main, *av);
		parse_arg(t_main, *av);
		pipe(t_main->pipes1);
		ft_maria(envp, t_main, pid);
		pipe(t_main->pipes2);
		if (*(av + 2) == NULL)
			t_main->last = 1;
		ft_fabien(envp, t_main, pid);
		ft_free_char(t_main, 0);
		av++;
	}
	ft_free_char(t_main, 1);
	return (wait_process(pid));
}

int	main(int ac, char **av, char **envp)
{
	t_pipe	t_main;
	int		status;

	if ((ac < 5) || (access(av[1], R_OK) != 0))
	{
		if (ac < 5)
			ft_printf("less arg than 5");
		else
			ft_printf("'%s' dosen't exist\n", av[1]);
		exit(EXIT_FAILURE);
	}
	else
	{
		init_path(&t_main, envp);
		t_main.in_fd = open(av[1], O_RDONLY);
		dup2(t_main.in_fd, STDIN_FILENO);
		t_main.out_fd = open(av[ac - 1], O_WRONLY | O_CREAT, O_TRUNC, 0777);
		av += 2;
		status = pipex(av, envp, &t_main);
		close(t_main.in_fd);
	}
	exit (status);
}
