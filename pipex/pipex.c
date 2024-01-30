/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 12:03:25 by ilyanar           #+#    #+#             */
/*   Updated: 2024/01/30 13:22:33 by ilyanar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "pipex.h"

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
	tab = ft_split(path_line(env, "PATH"), ':');
	if (!tab)
	{
		ft_free_tab(tab);
		return (0);
	}
	path = ft_strdup(ft_strchr(tab[0], '=') + 1);
	free(tab[0]);
	tab[0] = path;
	while (++i, tab[i])
		ft_printf("%s\n", tab[i]);
	return (1);
}

int	true_command(char **tab)
{
	(void)tab;
	return (0);
}

int	exec_command(char **av)
{
	(void)av;
	return (0);
}

int	pipex(char **av, char **envp, int ac)
{
	int		i;
	char	**tab;

	tab = 0;
	i = -1;
	if (check_path(tab, envp) == 0)
	{
		perror("\033[31mError path\033[0m");
		exit(EXIT_FAILURE);
	}
	while (++i < ac)
	{
		if (true_command(tab) == 1)
			exec_command(av);
	}
	return (free_tab(tab) + 1);
}

/*	if (waitpid(pid, NULL, 0))
	{
		open(av[ac], O_CREAT | O_TRUNC | O_WRONLY, 0644);
		ft_printf("end\n");
	}
*/

int	main(int ac, char **av, char **envp)
{
	if (((ac < 5) || (access(av[1], R_OK) != 0)))
	{
		perror("Error");
		exit(EXIT_FAILURE);
	}
	else
		pipex(av, envp, ac);
	ft_printf("test\n");
	return (0);
}
