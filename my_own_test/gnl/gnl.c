/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 10:08:20 by ilyanar           #+#    #+#             */
/*   Updated: 2024/05/15 10:37:21 by ilyanar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gnl.h"
#include <cstdio>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "../../libft/libft.h"

char	*get_next_line(int fd)
{
	char			*lol;
	char			*new;
	static char		*tmp;
	int				code;

	lol = calloc(BUFFER_SIZE + 1, sizeof(char));
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) == -1)
		return ("probleme\n");
	else
	{
		code = read(fd, lol, BUFFER_SIZE);
		if (tmp)
		{
			lol = strj
		}
		lol[code] = '\0';
		if (strchr(lol, '\n'))
		{
			new = calloc(strchr(lol, '\n') - lol, sizeof(char));
			strncpy(new, lol, strchr(lol, '\n') - lol);
			tmp = strdup(strchr(lol));
		}
		return (lol);
	}
}

int	main(void)
{
	char	*str;

	for (int d = 0; d < 5; d++)
	{
		str = get_next_line(STDIN_FILENO);
		printf("str[%d]: %s\n", d, str);
	}
}
