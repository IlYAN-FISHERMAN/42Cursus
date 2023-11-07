/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 14:56:56 by ilyanar           #+#    #+#             */
/*   Updated: 2023/11/07 21:58:38 by ilyanar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	if (!(unsigned char)c)
		return ((char *)s + ft_strlen(s));
	while (*s && *s != (unsigned char)c)
		s++;
	if (*s == '\0')
		return (0);
	return ((char *)s);
}

char	*ft_gnljoin(char *buffer)
{
	char	*tmp;
	int		i;

	i = 0;
	if (!buffer)
		buffer = ft_calloc(1, sizeof(char));
	if (!buffer)
		return (NULL);
	while (buffer[i])
	{
		if (buffer[i] == '\n')
		{
			i++;
			break ;
		}
		i++;
	}
	tmp = (char *)ft_calloc(i + 1, sizeof(char));
	if (!tmp)
		return (NULL);
	ft_memcpy(tmp, buffer, i);
	return (tmp);
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
	i = ft_strlen(next_line + k);
	buffer = ft_calloc(i + 1, sizeof(char));
	if (!buffer)
		return (NULL);
	while (next_line[j + k])
	{
		buffer[j] = next_line[j + k];
		j++;
	}
	free(next_line);
	next_line = NULL;
	return (buffer);
}

char	*get_line(char *buffer, char *next_line, int fd)
{
	int	byte;

	byte = 1;
	if (!buffer)
		buffer = ft_calloc(1, sizeof(char));
	if (!buffer)
		return (NULL);
	while (byte != 0)
	{
		byte = read(fd, next_line, BUFFER_SIZE);
		if (byte == -1)
		{
			free(next_line);
			return (NULL);
		}
		else if (byte == 0)
			break ;
		next_line[byte] = '\0';
		buffer = ft_strjoin(buffer, next_line);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	free(next_line);
	next_line = NULL;
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char		*buffer;
	char			*next_line;
	char			*tmp;

	tmp = NULL;
	if (fd < 0 || BUFFER_SIZE < 0 || !fd)
		return (NULL);
	next_line = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!next_line)
		return (NULL);
	buffer = get_line(buffer, next_line, fd);
	tmp = ft_gnljoin(buffer);
	if (ft_strchr(buffer, '\n'))
		buffer = next_funct(buffer);
	else if (buffer && buffer[0] != '\0')
	{
		free(buffer);
		buffer = NULL;
	}
	if (ft_strlen(tmp) <= 0)
	{
		free(tmp);
		return (NULL);
	}
	return (tmp);
}

int	main(void)
{
	int	fd;
	int	i;
	int	j;

	j = 1;
	i = 0;
	fd = open("41_no_nl", O_RDONLY);
	while (i < 1)
	{
		printf("  -------------------\n");
		printf("|  FONCTION NUMBER %d  |\n", j);
		printf("  -------------------\n");
		printf("\n\nFINAL LINE %d ->_%s\n\n------\n\n", j, get_next_line(fd));
		i++;
		j++;
	}
	printf("\n\nEND OF THE PROGRAM !\n\n");
	return (0);
}
