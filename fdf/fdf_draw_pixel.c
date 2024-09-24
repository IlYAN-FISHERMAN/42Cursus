/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw_pixel.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 17:33:18 by ilyanar           #+#    #+#             */
/*   Updated: 2024/09/20 14:19:57 by ilyanar          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft/libft.h"
#include "minilibx_macos/mlx.h"

void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && y >= 0 && x < WIDTH && y < HEIGHT)
	{
		dst = data->addr + (y * data->line_length + x \
			*(data->byte_per_pixel >> 3));
		*(unsigned int *)dst = color;
	}
}

void	next_line(t_fdf *mlx, int y)
{
	mlx->pos->sep = WIDTH / max1(mlx->len->lon, mlx->len->larg) - mlx->pos->zom;
	mlx->pos->x = mlx->pos->beg + mlx->pos->difx;
	mlx->pos->xl = mlx->pos->x + mlx->pos->sep;
	mlx->pos->y = mlx->pos->beg + mlx->pos->x + (mlx->pos->sep * y) + \
		mlx->pos->dify;
	mlx->pos->yl = mlx->pos->y;
}

void	draw(t_fdf *mlx)
{
	int	x;
	int	y;

	y = -1;
	while (++y < mlx->len->larg)
	{
		x = -1;
		next_line(mlx, y);
		mlx->len->lat = ft_split(mlx->len->map[y], ' ');
		while (++x < mlx->len->lon)
		{
			calcule_z_1(mlx, x);
			bresenham(mlx->pos->xl, mlx->pos->yl, mlx);
			mlx->pos->xl = mlx->pos->x;
			mlx->pos->yl += mlx->pos->sep;
			calcule_z_2(mlx, x, y);
			if (y + 1 < mlx->len->larg)
				bresenham(mlx->pos->xl, mlx->pos->yl, mlx);
			mlx->pos->x += mlx->pos->sep;
			mlx->pos->yl -= mlx->pos->sep;
		}
		ft_free_tab(mlx->len->lat);
	}
	mlx_put_image_to_window(mlx->pid, mlx->pid_win, mlx->img->img, 0, 0);
}

void	calcule_z_2(t_fdf *mlx, int x, int y)
{
	char	**tmp;

	tmp = NULL;
	if (y + 1 < mlx->len->larg && ft_strchr(mlx->len->lat[x], ',') != NULL)
	{
		z2_color(mlx, mlx->len->lat[x]);
	}
	else
	{
		mlx->pos->z = ft_atoi(mlx->len->lat[x]) * mlx->pos->alt;
		is_rgb(mlx);
	}
	if (y + 1 < mlx->len->larg)
	{
		tmp = ft_split(mlx->len->map[y + 1], ' ');
		if (tmp != NULL && ft_strchr(tmp[x], ',') != NULL)
			z2l_color(mlx, x, tmp);
		else
		{
			mlx->pos->zl = ft_atoi(tmp[x]) * mlx->pos->alt;
			is_rgb(mlx);
		}
		ft_free_tab(tmp);
	}
}

void	calcule_z_1(t_fdf *mlx, int x)
{
	if (ft_strchr(mlx->len->lat[x], ',') != NULL)
		z1_color(mlx, x);
	else
	{
		mlx->pos->z = ft_atoi(mlx->len->lat[x]) * mlx->pos->alt;
		is_rgb(mlx);
	}
	if (x > 0 || x == 0)
	{
		if (x > 0 && ft_strchr(mlx->len->lat[x - 1], ',') != NULL)
			zl1_color(mlx, x);
		else if (x == 0 && ft_strchr(mlx->len->lat[x + 1], ',') != NULL)
			zl1_color(mlx, x);
		else
		{
			if (x > 0)
				mlx->pos->zl = ft_atoi(mlx->len->lat[x - 1]) * mlx->pos->alt;
			else if (x == 0)
				mlx->pos->zl = ft_atoi(mlx->len->lat[x + 1]) * mlx->pos->alt;
			is_rgb(mlx);
		}
	}
}
