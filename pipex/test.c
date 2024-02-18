/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 18:51:20 by ilyanar           #+#    #+#             */
/*   Updated: 2024/02/17 19:03:51 by ilyanar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <sys/_types/_pid_t.h>
#include <sys/fcntl.h>
#include <sys/wait.h>
#include <unistd.h>

int	main(int ac, char **av, char **env)
{
	int	pip[2];
	char *tab1[] = {"cat", NULL, NULL};
	char *tab2[] = {"wc", NULL, NULL};
	int fd1 = open(av[1], O_RDONLY);
	int	fd2 = open(av[ac - 1], O_WRONLY, O_TRUNC, 0777);
	pid_t pid = fork();
	
	pipe(pip);
	dup2(fd1, STDIN_FILENO);
	if (pid == 0)
	{
		close(pip[0]);
		dup2(pip[1], STDOUT_FILENO);
		close(pip[1]);
		execve("/bin/cat", tab1, env);
		printf("error\n");
	}
	else
	{
		waitpid(pid, NULL, 0);
		dup2(fd2, STDOUT_FILENO);
		execve("/bin/wc", tab2, env);
		printf("error\n");
	}
}
