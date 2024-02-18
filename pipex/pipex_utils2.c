/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 12:53:02 by ilyanar           #+#    #+#             */
/*   Updated: 2024/02/17 17:14:48 by ilyanar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "libft/libft.h"

void	ft_check_error(char *file, int *lfile, int *pipes)
{
	unlink(file);
	*lfile = open(file, O_CREAT | O_WRONLY, S_IRUSR | S_IWUSR);
	ft_printf("fd : %d\n");
	if (*lfile == -1)
		ft_strerror("open can't be open", 0, NULL, NULL);
	if (pipe(pipes) == -1)
		ft_strerror("pipe", 0, NULL, NULL);
}

void	ft_strerror(char *tab, int cmd, char *av, t_pipe *t_main)
{
	if (t_main->cmd_alone)
		free(t_main->cmd_alone);
	if (t_main->path)
		free(t_main->path);
	if (t_main->env)
		ft_free_tab(t_main->env);
	if (t_main->args)
		ft_free_tab(t_main->args);
	if (cmd == 1)
		ft_printf("'%s' not a real command ", av);
	else if (tab)
		perror(tab);
	exit(EXIT_FAILURE);
}

void	init_path(t_pipe *t_main, char **env)
{
	char	*path;

	ft_bzero(t_main, sizeof(t_pipe));
	path = NULL;
	t_main->env = ft_split(strchr_path_line(env), ':');
	path = ft_strdup(ft_strchr(t_main->env[0], '=') + 1);
	free(t_main->env[0]);
	t_main->env[0] = path;
}

char	*strchr_path_line(char **env)
{
	int			i;
	int			j;
	const char	path[] = "PATH";

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
