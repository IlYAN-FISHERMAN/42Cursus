/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 14:57:14 by ilyanar           #+#    #+#             */
/*   Updated: 2023/11/02 22:58:21 by ilyanar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	len(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] && s[i] != '\n')
		i++;
	return (i);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t		i;
	char		*d;
	const char	*s;

	d = (char *)dst;
	s = (const char *)src;
	i = -1;
	if (!dst || !src)
		return (NULL);
	while (i++, i != n && ((char *)src)[i] != '\n')
		d[i] = s[i];
	return (dst);
}

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*tmp;

	if (!lst)
		return (NULL);
	tmp = lst;
	while (tmp)
	{
		if (tmp->next == NULL)
			return (tmp);
		else
			tmp = tmp->next;
	}
	return (tmp);
}

int	have_n(char *tab)
{
	int	i;

	i = 0;
	if (!tab)
		return (0);
	while (tab[i])
	{
		if (tab[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

void	stack_buffer(char *tab, int byte)
{
	int	i;
	int	j;

	j = 0;
	if (!tab || !byte)
		return ;
	i = len(tab) + 1;
	while (i < byte)
	{
		tab[j] = tab[i];
		i++;
		j++;
	}
	while (j < byte)
	{
		tab[j] = '\0';
		j++;
	}
}
