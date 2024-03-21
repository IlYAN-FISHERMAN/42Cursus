/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 17:18:12 by ilyanar           #+#    #+#             */
/*   Updated: 2024/03/21 19:35:24 by ilyanar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "fdf.h"

char	*joint_line(char *s1, char *s2)
{
	char	*s3;

	if (!s1 || !s2)
		return (NULL);
	s3 = (char *)ft_calloc(ft_strlen(s1) + ft_strlen(s2) + 1, sizeof(char));
	if (!s3)
		return (NULL);
	ft_memcpy(s3, s1, ft_strlen(s1));
	ft_memcpy((s3 + ft_strlen(s1)), s2, ft_strlen(s2));
	free(s1);
	return (s3);
}

void	get_lines_larg_len(t_fdf *mlx)
{
	char	**line;
	char	*buf;
	char	*tmp;
	int		count;

	mlx->len->larg = 0;
	buf = get_next_line(mlx->fd);
	if (!buf)
		freexit(mlx);
	while (++mlx->len->larg)
	{
		tmp = get_next_line(mlx->fd);
		if (tmp == NULL)
			break ;
		buf = joint_line(buf, tmp);
		free(tmp);
	}
	mlx->len->map = ft_split(buf, '\n');
	count = 0;
	line = ft_split(mlx->len->map[0], ' ');
	while (line[count])
		count++;
	mlx->len->lon = count;
	free(buf);
	ft_free_tab(line);
}
