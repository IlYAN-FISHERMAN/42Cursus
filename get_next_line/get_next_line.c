/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 14:56:56 by ilyanar           #+#    #+#             */
/*   Updated: 2023/11/01 18:05:38 by ilyanar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char	*buffer;
	char	*next_line;
	int		byte_nb;

	byte_nb = -1;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &next_line, 0) < 0)
		return (NULL);
	while (byte_nb != 0)
		byte_nb = read(fd, next_line, BUFFER_SIZE);
	return (ft_strdup(buffer));
}
/*
int	main(void)
{
	int			fd;

	fd = open("test.txt", O_RDONLY);
	get_next_line(fd);
}
*/
