/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_config.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 17:20:15 by ilyanar           #+#    #+#             */
/*   Updated: 2024/03/20 18:26:19 by ilyanar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft/libft.h"
#include "minilibx_macos/mlx.h"
#include <stdlib.h>

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
	mlx->tree_d = ft_calloc(1, sizeof(t_3d));
	if (!mlx->tree_d)
		freexit(mlx);
	mlx->pid = mlx_init();
	if (!mlx->pid)
		freexit(mlx);
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
	if (mlx->tree_d)
		free(mlx->tree_d);
	if (mlx->len->map)
		ft_free_tab(mlx->len->map);
	if (mlx->len)
		free(mlx->len);
	close(mlx->fd);
	exit(EXIT_SUCCESS);
}
