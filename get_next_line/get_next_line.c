/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 14:56:56 by ilyanar           #+#    #+#             */
/*   Updated: 2023/11/02 17:42:34 by ilyanar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	ft_lstlast(*lst)->content = malloc(len(tab) + 1 * sizeof(char));
	if (!ft_lstlast(*lst)->content)
		return ;
	ft_memcpy(ft_lstlast(*lst)->content, tab, len(tab) + 1);
}

void	cpy_all_node(t_list **lst, char *buffer)
{
	t_list *tmp;
	int	i;
	int	j;

	i = 0;
	j = 0;
	tmp = lst;
	while (tmp->next != NULL)
	{
		while(tmp->content[i])
		{
			i++;
			j++;
		}
		i = 0;
	}
	tmp = tmp->next;
}

char	*get_next_line(int fd)
{
	char	*buffer;
	char	*next_line;
	int		byte_nb;
	t_list	*lst;

	lst = NULL;
	byte_nb = -1;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &next_line, 0) < 0)
		return (NULL);
	while (byte_nb != 0)
	{
		byte_nb = read(fd, next_line, BUFFER_SIZE);
		if (have_n(next_line) == 1)
			return (NULL);
		else
			ft_cpy_node(&lst, next_line);
	}
	cpy_all_node(&lst, buffer);
	return (buffer);
}

#include <stdio.h>
int	main()
{
	int	fd;

	fd = open("text.txt" || O_RDONLY);
	printf("%s", get_next_line(fd));
}
