/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_keys.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 17:17:02 by ilyanar           #+#    #+#             */
/*   Updated: 2024/03/21 23:44:46 by ilyanar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "fdf.h"
#include "minilibx_macos/mlx.h"

int	close_win(t_fdf *mlx)
{
	ft_printf("fdf: the window was closed whit X\n");
	freexit(mlx);
	return (1);
}

void	reset(t_fdf *mlx)
{
	mlx->pos->beg = 50;
	mlx->pos->line_color = 0xffffff;
	mlx->pos->iso = 0.7;
	mlx->pos->alt = 1;
	mlx->pos->difx = 480;
	mlx->pos->dify = -800;
	mlx->pos->zom = -3;
	mlx->pos->yl = 0;
	mlx->pos->x = 0;
	mlx->pos->xl = 0;
	mlx->pos->yl = 0;
	mlx->pos->ra = 0;
	mlx->pos->rb = 0;
	mlx->tree_d->center_x = 750;
	mlx->tree_d->center_y = 750;
	mlx->tree_d->angle_x = 0.0;
	mlx->tree_d->angle_y = 0.0;
}

void	keys2(t_fdf *mlx, int keycode)
{
	if (keycode == 37)
		mlx->tree_d->angle_y += 3;
	else if (keycode == 41)
		mlx->tree_d->angle_y -= 3;
	else if (keycode == 38)
		mlx->tree_d->angle_x += 3;
	else if (keycode == 40)
		mlx->tree_d->angle_x -= 3;
	else if (keycode == 15)
		reset(mlx);
}

void	keys(t_fdf *mlx, int keycode)
{
	if (keycode == 124 || keycode == 2)
		mlx->pos->dify -= 30;
	else if (keycode == 123 || keycode == 0)
		mlx->pos->dify += 30;
	else if (keycode == 125 || keycode == 1)
		mlx->pos->difx += 30;
	else if (keycode == 126 || keycode == 13)
		mlx->pos->difx -= 30;
	else if (keycode == 12)
		mlx->pos->iso -= 0.01;
	else if (keycode == 14)
		mlx->pos->iso += 0.01;
	else if (keycode == 36 && mlx->pos->zom > -500)
		mlx->pos->zom -= 2;
	else if (keycode == 51 && mlx->pos->zom < 500)
		mlx->pos->zom += 2;
	else if (keycode == 31 && mlx->pos->alt * 10 >= -450)
		mlx->pos->alt -= 0.531415;
	else if (keycode == 35 && mlx->pos->alt * 10 <= 450)
		mlx->pos->alt += 0.531415;
	else
		keys2(mlx, keycode);
}

int	key_hooks(int keycode, t_fdf *mlx)
{
	if (keycode == 53)
		ft_printf("fdf: the window was closed\n");
	if (keycode == 53)
		freexit (mlx);
	ft_printf("key: %d\n", keycode);
	mlx_destroy_image(mlx->pid, mlx->img->img);
	mlx->img->img = mlx_new_image(mlx->pid, HEIGHT, WIDTH);
	mlx->img->addr = mlx_get_data_addr(mlx->img->img, \
		&mlx->img->byte_per_pixel, \
			&mlx->img->line_length, &mlx->img->endian);
	keys(mlx, keycode);
	draw(mlx);
	if (keycode != 4)
		mlx_string_put(mlx->pid, mlx->pid_win, 50, 50, 0xffffff, \
			"Press 'h' for help");
	mlx_string_put(mlx->pid, mlx->pid_win, 665, 20, 0xffffff, \
		"Welcome to FDF!");
	if (keycode == 4)
		draw_tuto(mlx);
	draw_numbers(mlx);
	return (1);
}
