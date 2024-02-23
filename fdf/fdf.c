/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 15:43:16 by ilyanar           #+#    #+#             */
/*   Updated: 2024/02/23 18:51:13 by ilyanar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft/libft.h"
#include "minilibx_macos/mlx.h"
#include <math.h>
#include <stdlib.h>

void	ft_error(int *ac, char **av)
{
	(void)av;
	if (*ac != 2)
		exit(EXIT_FAILURE);
}

void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x \
		*(data->byte_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	close_key(int keycode, t_fdf *mlx)
{
	(void)keycode;
	mlx_destroy_window(mlx->mlx, mlx->mlx_win);
	exit (0);
}

int	main(int ac, char **av)
{
	t_fdf	mlx;

	(void)ac;
	(void)av;
	ft_bzero(&mlx, sizeof(t_fdf));
	mlx.img = ft_calloc(1, sizeof(t_img));
	mlx.pos = ft_calloc(1, sizeof(t_pos));
	mlx.mlx = mlx_init();
	mlx.mlx_win = mlx_new_window(mlx.mlx, 1280, 720, "Moi");
	mlx.img->img = mlx_new_image(mlx.mlx, 1280, 720);
	mlx.img->addr = mlx_get_data_addr(mlx.img->img, &mlx.img->byte_per_pixel, \
							&mlx.img->line_length, &mlx.img->endian);
	while (mlx.pos->y < 720)
	{
		while (mlx.pos->x < 1280)
		{
			if ((mlx.pos->x > 440 && mlx.pos->x < 840) \
				&& (mlx.pos->y > 140 && mlx.pos->y < 580))
				my_mlx_pixel_put(mlx.img, mlx.pos->x, mlx.pos->y, 0x008D00FF);
			mlx.pos->x += 1;
		}
		mlx.pos->x = 0;
		mlx.pos->y++;
	}
	mlx_put_image_to_window(mlx.mlx, mlx.mlx_win, mlx.img->img, 0, 0);
	mlx_hook(mlx.mlx_win, 2, 1L << 0, close_key, &mlx.mlx);
	mlx_loop(mlx.mlx);
}
