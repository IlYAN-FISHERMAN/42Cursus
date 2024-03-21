/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_maths.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 13:52:15 by ilyanar           #+#    #+#             */
/*   Updated: 2024/03/21 22:07:26 by ilyanar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

void	rotate_y_axis(float *x, float *z, double angle)
{
	double	radians;
	float	old_x;

	radians = angle * M_PI / 180;
	old_x = *x;
	*x = (float)(old_x * cos(radians) + *z * sin(radians));
	*z = (float)(-old_x * sin(radians) + *z * cos(radians));
}

void	rotate_z_axis(float *x, float *y, double angle)
{
	double	radians;
	float	old_x;
	float	old_y;

	radians = angle * M_PI / 180.0;
	old_x = *x;
	old_y = *y;
	*x = (float)(old_x * cos(radians) - old_y * sin(radians));
	*y = (float)(old_x * sin(radians) + old_y * cos(radians));
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
	rotate_y_axis(&y, &mlx->pos->z, mlx->tree_d->angle_y);
	rotate_y_axis(&yl, &mlx->pos->zl, mlx->tree_d->angle_y);
	rotate_z_axis(&x, &y, mlx->tree_d->angle_x);
	rotate_z_axis(&xl, &yl, mlx->tree_d->angle_x);
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
