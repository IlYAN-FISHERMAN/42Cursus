/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 14:56:56 by ilyanar           #+#    #+#             */
/*   Updated: 2023/12/27 17:41:49 by ilyanar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_invalid(char **buffer, int fd)
{
	if (fd < 0 || BUFFER_SIZE < 0 || read(fd, 0, 0) == -1)
	{
		free(*buffer);
		*buffer = 0;
		return (1);
	}
	return (0);
}

char	*ft_gnljoin(char *s2)
{
	char	*s3;
	int		i;

	i = 0;
	if (!s2)
		s2 = calloc_gnl(1, sizeof(char));
	if (!s2)
		return (NULL);
	while (s2[i])
	{
		if (s2[i] == '\n')
		{
			i++;
			break ;
		}
		i++;
	}
	s3 = (char *)calloc_gnl(i + 1, sizeof(char));
	if (!s3)
		return (NULL);
	memcpy_gnl(s3, s2, i);
	return (s3);
}

char	*next_funct(char *next_line)
{
	char	*buffer;
	int		i;
	int		j;
	int		k;

	k = 0;
	i = 0;
	j = 0;
	while (next_line[k] != '\n')
		k++;
	k++;
	i = strlen_gnl(next_line + k);
	buffer = calloc_gnl(i + 1, sizeof(char));
	if (!buffer)
		return (NULL);
	while (next_line[j + k])
	{
		buffer[j] = next_line[j + k];
		j++;
	}
	free(next_line);
	return (buffer);
}

char	*get_nline(char *buffer, char *next_line, int *fd)
{
	int		byte;

	byte = 1;
	if (!buffer)
		buffer = calloc_gnl(1, sizeof(char));
	if (!buffer)
		return (NULL);
	while (byte != 0)
	{
		byte = read(*fd, next_line, BUFFER_SIZE);
		if (byte == -1)
		{
			*fd = -1;
			return (NULL);
		}
		else if (byte == 0)
			break ;
		next_line[byte] = '\0';
		buffer = strjoin_gnl(buffer, next_line);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	free(next_line);
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char		*buffer;
	char			*next_line;

	if (ft_invalid(&buffer, fd) != 0)
		return (NULL);
	next_line = calloc_gnl(BUFFER_SIZE + 1, sizeof(char));
	if (!next_line)
		return (NULL);
	buffer = get_nline(buffer, next_line, &fd);
	next_line = ft_gnljoin(buffer);
	if (ft_strchr(buffer, '\n'))
		buffer = next_funct(buffer);
	else if (buffer)
	{
		free(buffer);
		buffer = 0;
	}
	if (strlen_gnl(next_line) <= 0)
	{
		if (next_line)
			free(next_line);
		return (NULL);
	}
	return (next_line);
}
