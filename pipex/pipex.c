/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 12:03:25 by ilyanar           #+#    #+#             */
/*   Updated: 2024/02/18 19:45:29 by ilyanar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "pipex.h"
#include <stdlib.h>
#include <sys/_types/_null.h>
#include <sys/_types/_pid_t.h>
#include <sys/fcntl.h>
#include <sys/unistd.h>
#include <sys/wait.h>
#include <unistd.h>

int	wait_process(t_list **pid)
{
	int		status;
	t_list	*tmp;

	tmp = *pid;
	status = 0;
	while (tmp)
	{
		waitpid(*(pid_t *)tmp->content, &status, 0);
		tmp = tmp->next;
	}
	if (WIFEXITED(status))
		status = WEXITSTATUS(status);
	else
		status = 0;
	ft_lstclear(pid, free);
	return (status);
}

void	ft_maria(char **env, t_pipe *t_main, t_list **pid)
{
	pid_t	*pidt;

	pidt = ft_calloc(1, sizeof(pid_t));
	pidt[0] = fork();
	if (pidt[0] == 0)
	{
		if (t_main->in_fd != -2)
		{
			dup2(t_main->in_fd, STDIN_FILENO);
			close(t_main->in_fd);
		}
		close(t_main->pipes1[0]);
		dup2(t_main->pipes1[1], STDOUT_FILENO);
		close(t_main->pipes1[1]);
		execve(t_main->path, t_main->args, env);
		ft_strerror("Execve error", 0, NULL, t_main);
	}
	else
	{
		ft_lstadd_back(pid, ft_lstnew(&pidt[0]));
		close(t_main->pipes1[1]);
	}
}

void	ft_init_cmd(char **av, t_pipe *t_main)
{
	path_command(*av, t_main);
	found_cmd_alone(t_main, *av);
	parse_arg(t_main, *av);
}

void	ft_fabien(char **env, t_pipe *t_main, t_list **pid)
{
	pid_t	*pidt;

	pidt = ft_calloc(1, sizeof(pid_t));
	pidt[0] = fork();
	if (pidt[0] == 0)
	{
		dup2(t_main->pipes1[0], STDIN_FILENO);
		close(t_main->pipes1[0]);
		close(t_main->pipes2[0]);
		if (t_main->last == 1)
		{
			dup2(t_main->out_fd, STDOUT_FILENO);
			close(t_main->out_fd);
			t_main->in_fd = -2;
		}
		else
			dup2(t_main->pipes2[1], STDOUT_FILENO);
		close(t_main->pipes2[1]);
		execve(t_main->path, t_main->args, env);
		ft_strerror("Execve error", 0, NULL, t_main);
	}
	else
	{
		ft_lstadd_back(pid, ft_lstnew(&pidt[0]));
		close(t_main->pipes2[1]);
		close(t_main->pipes1[0]);
	}
}

int	pipex(char **av, char **envp, t_pipe *t_main)
{
	t_list	*pid;
	int		pair_impar;

	pair_impar = 1;
	pid = NULL;
	pipe(t_main->pipes1);
	while (*av && *(av + 1) != NULL)
	{
		ft_init_cmd(av, t_main);
		if (pair_impar == 1)
		{
			ft_maria(envp, t_main, &pid);
			pair_impar = 0;
		}
		else if (pair_impar == 0)
		{
			pipe(t_main->pipes2);
			if (*(av + 2) == NULL)
				t_main->last = 1;
			ft_fabien(envp, t_main, &pid);
			*t_main->pipes1 = *t_main->pipes2;
		}
		ft_free_char(t_main, 0);
		av++;
	}
	ft_free_char(t_main, 1);
	return (wait_process(&pid));
}

int	main(int ac, char **av, char **envp)
{
	t_pipe	t_main;
	int		status;

	status = -1;
	t_main.last = 0;
	if ((ac < 5) || (access(av[1], R_OK) != 0))
	{
		if (ac < 5)
		{
			ft_printf("less arg than 5");
			exit(EXIT_FAILURE);
		}
		else
			perror("access in_file ");
	}
	else
	{
		init_path(&t_main, envp);
		t_main.in_fd = open(av[1], O_RDONLY);
		if (access(av[ac - 1], W_OK | R_OK) != 0)
			unlink(av[ac - 1]);
		t_main.out_fd = open(av[ac - 1], O_WRONLY | O_CREAT, 00777);
		av += 2;
		status = pipex(av, envp, &t_main);
		close(t_main.in_fd);
	}
	exit (status);
}
