/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_maths.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 13:52:15 by ilyanar           #+#    #+#             */
/*   Updated: 2024/03/08 09:54:26 by ilyanar          ###   ########.fr       */
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

void	bresenham(t_fdf *mlx)
{
	float	max;

	mlx->pos->x *= mlx->pos->zoom;
	mlx->pos->xl *= mlx->pos->zoom;
	mlx->pos->y *= mlx->pos->zoom;
	mlx->pos->yl *= mlx->pos->zoom;
	mlx->pos->x_step = mlx->pos->xl - mlx->pos->x;
	mlx->pos->y_step = mlx->pos->yl - mlx->pos->y;
	max = max1(mod(mlx->pos->x_step), mod(mlx->pos->y_step));
	mlx->pos->x_step /= max;
	mlx->pos->y_step /= max;
	while ((int)(mlx->pos->x - mlx->pos->xl) \
		|| (int)(mlx->pos->y - mlx->pos->yl))
	{
		my_mlx_pixel_put(mlx->img, mlx->pos->x, mlx->pos->y, \
				mlx->pos->line_color);
		mlx->pos->x += mlx->pos->x_step;
		mlx->pos->y += mlx->pos->y_step;
	}
}

void	draw(t_fdf *mlx)
{
	mlx->pos->y = 0;
	while (mlx->pos->y < mlx->len->larg)
	{
		mlx->pos->x = 0;
		while (mlx->pos->x < mlx->len->lon)
		{
			mlx->pos->xl = mlx->pos->x + 1;
			bresenham(mlx);
			mlx->pos->xl = mlx->pos->x;
			mlx->pos->yl = mlx->pos->y + 1;
			bresenham(mlx);
			mlx->pos->x++;
		}
		mlx->pos->y++;
	}
}
