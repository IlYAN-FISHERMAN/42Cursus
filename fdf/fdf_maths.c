/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_maths.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 13:52:15 by ilyanar           #+#    #+#             */
/*   Updated: 2024/03/12 21:56:57 by ilyanar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft/libft.h"
#include "minilibx_macos/mlx.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/fcntl.h>

float	max1(float a, float b)
{
	if (a > b)
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

void	bresenham(float xl, float yl, t_fdf *mlx)
{
	float	max;
	float	x;
	float	y;

	x = mlx->pos->x;
	y = mlx->pos->y;
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

void	calcule_z_pos(t_fdf *mlx, int x)
{
	char	**tab;

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
}

void	next_line(t_fdf *mlx, int y, int x)
{
	mlx->pos->x = mlx->pos->beg;
	mlx->pos->y = mlx->pos->x + (mlx->pos->sep * y);
	mlx->pos->xl = mlx->pos->x + mlx->pos->sep;
	mlx->pos->yl = mlx->pos->y;
	if ((y + 1) == mlx->len->larg)
	{
		mlx->pos->x = mlx->pos->beg;
		mlx->pos->y = mlx->pos->x + (mlx->pos->sep * y);
		mlx->pos->xl = mlx->pos->x + (mlx->pos->sep * (x - 1));
		mlx->pos->yl = mlx->pos->y;
		bresenham(mlx->pos->xl, mlx->pos->yl, mlx);
	}
}

void	init_numbers(t_fdf *mlx)
{
	mlx->pos->x = mlx->pos->beg;
	mlx->pos->xl = mlx->pos->beg + mlx->pos->sep;
	mlx->pos->y = mlx->pos->beg;
	mlx->pos->yl = mlx->pos->beg;
	mlx->pos->line_color = 0xffffff;
	mlx->pos->sep = WIDTH / (mlx->len->lon + mlx->len->larg);
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
		mlx->len->lat = ft_split(mlx->len->map[y], ' ');
		while (++x < mlx->len->lon)
		{
			calcule_z_pos(mlx, x);
			bresenham(mlx->pos->xl, mlx->pos->yl, mlx);
			mlx->pos->xl = mlx->pos->x;
			mlx->pos->yl += mlx->pos->sep;
			bresenham(mlx->pos->xl, mlx->pos->yl, mlx);
			mlx->pos->x += mlx->pos->sep;
			mlx->pos->yl -= mlx->pos->sep;
		}
		ft_free_tab(mlx->len->lat);
		next_line(mlx, y, x);
	}
	mlx_put_image_to_window(mlx->pid, mlx->pid_win, mlx->img->img, 0, 0);
}
