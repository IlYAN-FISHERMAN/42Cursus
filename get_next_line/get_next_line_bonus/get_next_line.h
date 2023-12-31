/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 14:57:07 by ilyanar           #+#    #+#             */
/*   Updated: 2023/11/08 22:57:27 by ilyanar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>

typedef struct s_list
{
	char			*content;
	struct s_list	*next;
}	t_list;

char	*get_next_line(int fd);

void	*ft_memcpy(void *dst, const void *src, size_t n);
void	ft_cpy_node(t_list **lst, char *tab);
void	clear_all_node(t_list **lst);
void	cpy_all_node(t_list **lst, char *buffer);
void	all_node(t_list **lst, char *buffer);
void	stack_buffer(char *tab, int byte);

t_list	*ft_lstlast(t_list *lst);

size_t	len(const char *s);

int		have_n(char *tab);

#endif
