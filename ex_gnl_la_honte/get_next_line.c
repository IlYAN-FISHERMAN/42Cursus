/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 14:56:56 by ilyanar           #+#    #+#             */
/*   Updated: 2023/11/02 23:33:30 by ilyanar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <stdlib.h>

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*tmp;
	t_list	*next;

	if (!lst || !del)
		return ;
	tmp = *lst;
	while (tmp)
	{
		next = tmp->next;
		if (tmp->content != NULL)
			del(tmp->content);
		free(tmp);
		tmp = next;
	}
	*lst = NULL;
}

void	ft_cpy_node(t_list **lst, char *tab)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return ;
	new->next = NULL;
	if (!lst || !new)
		return ;
	if (!*lst)
		*lst = new;
	else
		ft_lstlast(*lst)->next = new;
	ft_lstlast(*lst)->content = calloc(len(tab) + 1, sizeof(char));
	if (!ft_lstlast(*lst)->content)
		return ;
	ft_memcpy(ft_lstlast(*lst)->content, tab, len(tab) + 1);
}

void	cpy_all_node(t_list **lst, char *buffer)
{
	t_list	*tmp;
	int		i;
	int		j;

	j = 0;
	i = 0;
	tmp = *lst;
	while (tmp->next != NULL)
	{
		while (tmp->content[i] != '\n' && tmp->content[i])
		{
			buffer[j] = tmp->content[i];
			i++;
			j++;
		}
		i = 0;
		tmp = tmp->next;
	}
}

void	all_node(t_list **lst, char *buffer)
{
	t_list	*tmp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	tmp = *lst;
	while (tmp->next != NULL)
	{
		while (tmp->content[i] && tmp->content[i] != '\n')
		{
			i++;
			j++;
		}
		i = 0;
		tmp = tmp->next;
	}
	buffer = malloc(j * sizeof(char));
	cpy_all_node(lst, buffer);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	static char	*next_line;
	int			byte_nb;
	t_list		*lst;

	lst = NULL;
	buffer = NULL;
	byte_nb = 1;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	next_line = calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!next_line)
		return (NULL);
	while (byte_nb > 0)
	{
		byte_nb = read(fd, next_line, BUFFER_SIZE);
		if (byte_nb < 0)
			return (NULL);
		ft_cpy_node(&lst, next_line);
		if (have_n(next_line) == 1)
			stack_buffer(next_line, byte_nb);
		if (have_n(next_line) == 1)
			break ;
	}
	all_node(&lst, buffer);
	ft_lstclear(&lst, free);
	return (buffer);
}

int	main(int ac, char **argv)
{
	int	fd;
	char	*path = argv[1];

	(void)ac;
	printf("%s\n", path);
	fd = open(path, O_RDONLY);
	if (fd < 0)
		perror("error");
	printf("%s", get_next_line(fd));
}
