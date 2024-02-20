/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 12:39:09 by ilyanar           #+#    #+#             */
/*   Updated: 2024/02/20 11:51:14 by ilyanar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "pipex.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/fcntl.h>
#include <unistd.h>

void	repuch_to_args(t_pipe *t_main, t_list *lst)
{
	int		i;
	int		j;
	t_list	*tmp;

	tmp = lst;
	i = ft_lstsize(lst);
	j = -1;
	t_main->args = ft_calloc(i + 1, sizeof(char **));
	while (++j < i && tmp != NULL)
	{
		(t_main)->args[j] = ft_strdup((char *)tmp->content);
		tmp = tmp->next;
	}
}

void	cpy_tab(char *tab, char **av, int i)
{
	int	j;

	j = 0;
	while (j < i)
	{
		tab[j] = av[0][j];
		j++;
	}
}

char	*init_tab(char *tab, char **av)
{
	int	i;

	i = -1;
	while (av[0][++i])
	{
		if (av[0][i] == '}' || av[0][i] == '{' \
			|| av[0][i] == 39 || av[0][i] == 34)
		{
			i++;
			while (!(av[0][i] == '}' || av[0][i] == '{' \
				|| av[0][i] == 39 || av[0][i] == 34))
				i++;
		}
		if (av[0][i] == 32)
		{
			i++;
			break ;
		}
	}
	tab = ft_calloc(i + 1, sizeof(char));
	cpy_tab(tab, av, i);
	if (i == 0)
		**av += 1;
	*av += i;
	return (tab);
}

void	parse_arg(t_pipe *t_main, char *av)
{
	char	*tab;
	t_list	*lst;

	t_main->args = NULL;
	tab = NULL;
	lst = NULL;
	while (*av)
	{
		tab = init_tab(tab, &av);
		ft_lstadd_back(&lst, ft_lstnew((char *)ft_strdup(tab)));
		free(tab);
		tab = NULL;
	}
	repuch_to_args(t_main, lst);
	ft_lstclear(&lst, free);
}

int	free_tab(char **tab)
{
	int	i;

	i = 0;
	if (!tab)
		return (-1);
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (0);
}
