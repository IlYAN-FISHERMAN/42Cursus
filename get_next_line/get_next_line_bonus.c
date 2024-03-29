/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 09:11:16 by ilyanar           #+#    #+#             */
/*   Updated: 2024/03/24 09:52:19 by ilyanar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_invalid(char **buffer, int fd)
{
	if (fd < 0 || BUFFER_SIZE < 0 || read(fd, 0, 0) == -1 || fd > 1023)
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

	i = -1;
	if (!s2)
		s2 = ft_calloc(1, sizeof(char));
	if (!s2)
		return (NULL);
	while (s2[++i])
		if (s2[i] == '\n' && ++i)
			break ;
	s3 = (char *)ft_calloc(i + 1, sizeof(char));
	if (!s3)
		return (NULL);
	ft_memcpy(s3, s2, i);
	return (s3);
}

char	*next_funct(char *next_line)
{
	char	*buffer;
	int		j;
	int		k;

	k = 0;
	j = 0;
	while (next_line[k] != '\n')
		k++;
	k++;
	j = ft_strlen(next_line + k);
	buffer = ft_calloc(j + 1, sizeof(char));
	if (!buffer)
		return (NULL);
	j = -1;
	while (next_line[++j + k])
		buffer[j] = next_line[j + k];
	free(next_line);
	return (buffer);
}

char	*get_nline(char *buffer, char *next_line, int *fd)
{
	int		byte;

	byte = 1;
	if (!buffer)
		buffer = ft_calloc(1, sizeof(char));
	if (!buffer)
		return (NULL);
	while (byte != 0)
	{
		byte = read(*fd, next_line, BUFFER_SIZE);
		if (byte == -1)
			return (NULL);
		else if (byte == 0)
			break ;
		next_line[byte] = '\0';
		buffer = ft_strjoin(buffer, next_line);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	free(next_line);
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char		*buffer[1024];
	char			*next_line;

	if (fd < 0 || ft_invalid(&buffer[fd], fd) != 0)
		return (NULL);
	next_line = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!next_line)
		return (NULL);
	buffer[fd] = get_nline(buffer[fd], next_line, &fd);
	next_line = ft_gnljoin(buffer[fd]);
	if (ft_strchr(buffer[fd], '\n'))
		buffer[fd] = next_funct(buffer[fd]);
	else if (buffer[fd])
	{
		free(buffer[fd]);
		buffer[fd] = 0;
	}
	if (ft_strlen(next_line) <= 0)
	{
		if (next_line)
			free(next_line);
		return (NULL);
	}
	return (next_line);
}
/*
int	main(void)
{
	int		fd;
	int		i;
	int		j;
	char	*tmp;

	j = 1;
	i = 0;
	fd = open("test.txt", O_RDONLY);
	while (i < 4)
	{
		tmp = get_next_line(fd);
		printf("  -------------------\n");
		printf("|  FONCTION NUMBER %d  |\n", j);
		printf("  -------------------\n");
		printf("\n\nFINAL LINE %d ->_%s\n\n------\n\n", j, tmp);
		free(tmp);
		i++;
		j++;
	}
	printf("\n\nEND OF THE PROGRAM !\n\n");
	return (0);
}*/
