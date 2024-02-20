/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 17:28:10 by ilyanar           #+#    #+#             */
/*   Updated: 2024/02/19 19:23:53 by ilyanar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../pipex.h"

void	ft_check_error(char *file, int *lfile, int *pipes)
{
	*lfile = open(file, O_CREAT | O_WRONLY, S_IRUSR | S_IWUSR);
	ft_printf("fd : %d\n");
	if (*lfile == -1)
		ft_strerror("open can't be open", 0, NULL, NULL);
	if (pipe(pipes) == -1)
		ft_strerror("pipe", 0, NULL, NULL);
}

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
		if (ft_strncmp(av[1], "here_doc", 9) == 0)
			ft_printf("here_doc\n");
		t_main.in_fd = open(av[1], O_RDONLY);
		t_main.out_fd = open(av[ac - 1], O_WRONLY | O_CREAT | O_TRUNC, 00644);
		av += 2;
		status = pipex(av, envp, &t_main, pid);
		close(t_main.in_fd);
	}
	exit (status);
}
