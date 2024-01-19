/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 12:03:25 by ilyanar           #+#    #+#             */
/*   Updated: 2024/01/19 03:12:48 by ilyanar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

int	main(int ac, char **av)
{
	char	*tab;
	int		fd;

	tab = 0;
	if (ac != 5)
	{
		perror("\033[31mError\033[0m");
		exit(EXIT_FAILURE);
	}
	else
	{
		fd = open(av[1], O_RDONLY);
		tab = ft_calloc(101, sizeof(char));
		read(fd, tab, 100);
		ft_printf("%s\n", tab);
		close(fd);
	}
	return (0);
}
