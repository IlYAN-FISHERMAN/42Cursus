/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 19:01:26 by ilyanar           #+#    #+#             */
/*   Updated: 2024/02/10 16:25:42 by ilyanar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "pipex.h"

void	ft_free_char(t_pipe *t_main, int cmd)
{
	if (t_main->path)
		free(t_main->path);
	t_main->path = NULL;
	if (t_main->cmd_alone)
		free(t_main->cmd_alone);
	if (t_main->arg)
		ft_free_tab(t_main->arg);
	if (cmd > 0)
		if (t_main->env)
			ft_free_tab(t_main->env);
}

void	parse_arg(t_pipe *t_main, char *av)
{
	(void)t_main;
	(void)av;
}

void	found_cmd_alone(t_pipe *t_main, char *av)
{
	int	i;
	int	j;

	j = -1;
	i = 0;
	while (av[i] && ft_isprint(av[i]) == 1 && av[i] > 32)
		i++;
	t_main->cmd_alone = ft_calloc(i + 1, sizeof(char));
	if (!t_main->cmd_alone)
		ft_strerror("Error malloc", 0, NULL, t_main);
	while (++j < i)
		t_main->cmd_alone[j] = av[j];
}

void	path_command(char *av, t_pipe *t_main)
{
	int		i;

	i = 0;
	while (t_main->env[i])
	{
		t_main->path = join_cmd_path(av, t_main->env[i]);
		if (access(t_main->path, F_OK) != -1)
			return ;
		free(t_main->path);
		i++;
	}
	return (ft_strerror(NULL, 1, av, t_main));
}

int	is_tring(char *av, char *str)
{
	int	i;

	i = 0;
	while (av[i] == str[i])
	{
		if (str[i] == '\0')
			return (1);
		i++;
		if (str[i] == '\0')
			return (1);
	}
	return (0);
}

char	**new_av(char **av, int ac)
{
	char	**tab;
	int		i;
	int		j;
	int		k;

	k = 0;
	i = 0;
	j = 0;
	tab = ft_calloc(ac - 1, sizeof(char **));
	if (!tab)
		return (NULL);
	while (av[j])
	{
		if (is_tring(av[j], "here_doc") == 1)
			j++;
		tab[k] = ft_calloc(ft_strlen(av[j]), sizeof(char));
		if (!tab[k])
			return (NULL);
		while (av[j][i] != '\0')
		{
			tab[k][i] = av[j][i];
			i++;
		}
		i = 0;
		j++;
		k++;
	}
	return (tab);
}
