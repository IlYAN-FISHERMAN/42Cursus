/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_maths.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 13:52:15 by ilyanar           #+#    #+#             */
/*   Updated: 2024/03/21 11:30:09 by ilyanar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

void	rotate(float x, float y, t_fdf *mlx)
{
	x = x - 20;
	y = y - 20;
	float angle = atan2(y, x);
	angle = angle * 180 / M_PI;
	if (angle < 0)
		angle += 90.0;
	else
		angle -= 90.0;
	mlx->pos->x += angle;
	mlx->pos->y -= angle;
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

	//rotate(mlx->pos->x, mlx->pos->y, mlx);
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
