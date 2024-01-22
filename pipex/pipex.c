/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 12:03:25 by ilyanar           #+#    #+#             */
/*   Updated: 2024/01/22 16:56:39 by ilyanar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/fcntl.h>
#include <sys/unistd.h>
#include <sys/wait.h>
#include <unistd.h>

int	main(int ac, char **av, char *envp[])
{
	int		pid;
	char	*arg[] = {av[2], NULL, NULL};
	char	**tab;

	tab = 0;
	if (ac < 1)
		exit(EXIT_FAILURE);
	pid = fork();
	if (pid == -1)
	{
		perror("\033[31mError\033[0m");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		tab = ft_split(envp[15], ':');
		if (access(av[2], F_OK) != -1)
			execve("/bin/ls", arg, NULL);
		perror("\033[31mError\033[0m");
		exit(EXIT_FAILURE);
	}
	else if (waitpid(pid, NULL, 0))
	{
		open("fdp", O_CREAT);
		ft_printf("end\n");
	}
	ft_free_tab(tab);
	return (0);
}
