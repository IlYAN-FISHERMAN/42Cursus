/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 13:41:25 by ilyanar           #+#    #+#             */
/*   Updated: 2024/03/12 22:55:20 by ilyanar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft/libft.h"
#include "minilibx_macos/mlx.h"

int	close_win(t_fdf *mlx)
{
	ft_printf("fdf: the window was closed whit X\n");
	freexit(mlx);
	return (1);
}

int	freexit(t_fdf *mlx)
{
	if (mlx->pos)
		free(mlx->pos);
	if (mlx->img)
		free(mlx->img);
	if (mlx->color)
		free(mlx->color);
	if (mlx->pid_win)
		mlx_destroy_window(mlx->pid, mlx->pid_win);
	close(mlx->fd);
	exit(EXIT_SUCCESS);
}

void	conf_win(t_fdf *mlx)
{
	ft_bzero(mlx, sizeof(t_fdf));
	alloc_all(mlx);
	mlx->pid_win = mlx_new_window(mlx->pid, HEIGHT, WIDTH, "Fil de fer");
	mlx->img->img = mlx_new_image(mlx->pid, HEIGHT, WIDTH);
	mlx->img->addr = mlx_get_data_addr(mlx->img->img, \
		&mlx->img->byte_per_pixel, &mlx->img->line_length, &mlx->img->endian);
}

void	alloc_all(t_fdf *mlx)
{
	mlx->img = ft_calloc(1, sizeof(t_img));
	if (!mlx->img)
		freexit(mlx);
	mlx->pos = ft_calloc(1, sizeof(t_pos));
	if (!mlx->pos)
		freexit(mlx);
	mlx->color = ft_calloc(1, sizeof(t_color));
	if (!mlx->color)
		freexit(mlx);
	mlx->len = ft_calloc(1, sizeof(t_len));
	if (!mlx->len)
		freexit(mlx);
	mlx->pid = mlx_init();
	if (!mlx->pid)
		freexit(mlx);
}

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

int	get_lines_larg_len(t_fdf *mlx)
{
	char	**line;
	char	*buf;
	char	*tmp;
	int		count;

	count = 1;
	buf = get_next_line(mlx->fd);
	while (1)
	{
		tmp = get_next_line(mlx->fd);
		if (tmp == NULL)
			break ;
		buf = joint_line(buf, tmp);
		free(tmp);
		count++;
	}
	mlx->len->map = ft_split(buf, '\n');
	mlx->len->larg = count;
	count = 0;
	line = ft_split(mlx->len->map[0], ' ');
	while (line[count])
		count++;
	mlx->len->lon = count;
	ft_free_tab(line);
	return (0);
}
