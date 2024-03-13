/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_maths.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 13:52:15 by ilyanar           #+#    #+#             */
/*   Updated: 2024/03/13 02:53:09 by ilyanar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft/libft.h"
#include "minilibx_macos/mlx.h"
#include <math.h>

float	max1(float a, float b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

float	min1(float a, float b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

float	mod(float i)
{
	if (i < 0)
		return (-i);
	else
		return (i);
}

void	isometric(float *x, float *y, int z)
{
	*x = (*x - *y) * cos (0.8);
	*y = (*x + *y) * sin(0.8) - z;
}

void	bresenham(float xl, float yl, t_fdf *mlx)
{
	float	max;
	float	x;
	float	y;

	x = mlx->pos->x;
	y = mlx->pos->y;
	isometric(&x, &y, mlx->pos->z);
	isometric(&xl, &yl, mlx->pos->zl);
	mlx->pos->x_step = xl - x;
	mlx->pos->y_step = yl - y;
	max = max1(mod(mlx->pos->x_step), mod(mlx->pos->y_step));
	mlx->pos->x_step /= max;
	mlx->pos->y_step /= max;
	while ((int)(x - xl) \
		|| (int)(y - yl))
	{
		my_mlx_pixel_put(mlx->img, x, y, mlx->pos->line_color);
		x += mlx->pos->x_step;
		y += mlx->pos->y_step;
	}
}

void	calcule_zl_pos(t_fdf *mlx, int x, int y)
{
	char	**tab;

	if ((y + 1) < mlx->len->larg)
	{
		tab = ft_split(mlx->len->map[y + 1], ' ');
		mlx->pos->zl = ft_atoi(tab[x]);
		ft_free_tab(tab);
	}
	else
		mlx->pos->zl = mlx->pos->z;
}

void	calcule_z_pos(t_fdf *mlx, int x, int y)
{
	char	**tab;

	(void)y;
	if (ft_strchr(mlx->len->lat[x], ',') != NULL)
	{
		tab = ft_split(mlx->len->lat[x], ',');
		mlx->pos->z = ft_atoi(tab[0]);
		mlx->pos->line_color = ft_atoi_base(tab[1], 16);
		ft_free_tab(tab);
	}
	else
	{
		mlx->pos->z = ft_atoi(mlx->len->lat[x]);
		if (mlx->pos->z > 0)
			mlx->pos->line_color = 0x810202;
		else if (mlx->pos->z < 0)
			mlx->pos->line_color = 0x089BCC;
		else
			mlx->pos->line_color = 0xffffff;
	}
	calcule_zl_pos(mlx, x, y);
}

void	next_line(t_fdf *mlx, int y, int x)
{
	(void)x;
	mlx->pos->x = mlx->pos->beg + mlx->pos->difx;
	mlx->pos->xl = mlx->pos->x + mlx->pos->sep;
	if (mlx->pos->z <= 0)
		mlx->pos->y = (mlx->pos->beg + mlx->pos->x + \
			(mlx->pos->sep * y) + mlx->pos->dify) - mlx->pos->z;
	else
		mlx->pos->y = mlx->pos->beg + mlx->pos->x + \
			(mlx->pos->sep * y) + mlx->pos->dify - mlx->pos->z;
	if (mlx->pos->zl <= 0)
		mlx->pos->yl = mlx->pos->y - mlx->pos->zl;
	else
		mlx->pos->yl = mlx->pos->y + mlx->pos->zl;
}

void	init_numbers(t_fdf *mlx)
{
	mlx->pos->x = mlx->pos->beg + mlx->pos->difx;
	mlx->pos->xl = mlx->pos->x + mlx->pos->sep;
	if (mlx->pos->z < 0)
		mlx->pos->y = mlx->pos->beg + mlx->pos->x + mlx->pos->sep + \
			mlx->pos->dify - mlx->pos->z;
	else
		mlx->pos->y = mlx->pos->beg + mlx->pos->x + mlx->pos->sep + \
			mlx->pos->dify + mlx->pos->z;
	if (mlx->pos->z < 0)
		mlx->pos->yl = mlx->pos->y - mlx->pos->z;
	else
		mlx->pos->yl = mlx->pos->y + mlx->pos->z;
}

void	draw(t_fdf *mlx)
{
	int	x;
	int	y;

	y = -1;
	init_numbers(mlx);
	while (++y < mlx->len->larg)
	{
		x = -1;
		next_line(mlx, y, x);
		mlx->len->lat = ft_split(mlx->len->map[y], ' ');
		while (++x < mlx->len->lon)
		{
			calcule_z_pos(mlx, x, y);
			bresenham(mlx->pos->xl, mlx->pos->yl, mlx);
			mlx->pos->xl = mlx->pos->x;
			mlx->pos->yl += mlx->pos->sep;
			if (y + 1 < mlx->len->larg)
				bresenham(mlx->pos->xl, mlx->pos->yl, mlx);
			mlx->pos->x += mlx->pos->sep;
			mlx->pos->yl -= mlx->pos->sep;
		}
		ft_free_tab(mlx->len->lat);
	}
	mlx_put_image_to_window(mlx->pid, mlx->pid_win, mlx->img->img, 0, 0);
}
