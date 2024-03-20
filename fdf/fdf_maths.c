/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_maths.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 13:52:15 by ilyanar           #+#    #+#             */
/*   Updated: 2024/03/20 17:32:09 by ilyanar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

void	rotate(t_fdf *mlx, int z)
{
	float	x_orig;
	float	z_orig;
	float	cos_angle;
	float	sin_angle;

	cos_angle = cos(mlx->pos->iso * M_PI / 90.0);
	sin_angle = sin(mlx->pos->iso * M_PI / 90.0);
	x_orig = mlx->pos->x;
	z_orig = z;
	mlx->pos->x = x_orig * cos_angle + z_orig * sin_angle;
	mlx->pos->z = -x_orig * sin_angle + z_orig * cos_angle;
}

void	isometric(float *x, float *y, int z, t_fdf *mlx)
{
	*x = (*x - *y) * cos(mlx->pos->iso);
	*y = (*x + *y) * sin(mlx->pos->iso) - z;
}

void	bresenham(float xl, float yl, t_fdf *mlx)
{
	float	max;
	float	x;
	float	y;

	x = mlx->pos->x;
	y = mlx->pos->y;
	isometric(&x, &y, mlx->pos->z, mlx);
	isometric(&xl, &yl, mlx->pos->zl, mlx);
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
