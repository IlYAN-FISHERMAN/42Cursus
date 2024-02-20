/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 14:41:54 by ilyanar           #+#    #+#             */
/*   Updated: 2024/02/19 19:16:13 by ilyanar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "libft/libft.h"
#include <sys/unistd.h>
#include <unistd.h>

int	main(int ac, char **av, char **envp)
{
	t_pipe	t_main;
	t_list	*pid;
	int		status;

	pid = NULL;
	status = 127;
	if ((ac < 5))
		ft_printf("less arg than 5");
	else
	{
		init_path(&t_main, envp);
		t_main.in_fd = open(av[1], O_RDONLY);
		unlink(av[ac - 1]);
		t_main.out_fd = open(av[ac - 1], O_WRONLY | O_CREAT | O_TRUNC, 00644);
		av += 2;
		status = pipex(av, envp, &t_main, pid);
		close(t_main.in_fd);
	}
	exit (status);
}
