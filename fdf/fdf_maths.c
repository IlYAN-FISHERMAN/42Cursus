/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_maths.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 13:52:15 by ilyanar           #+#    #+#             */
/*   Updated: 2024/03/18 23:46:14 by ilyanar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft/libft.h"
#include "minilibx_macos/mlx.h"
#include <math.h>
#include <stdio.h>

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

int	is_rgb(t_fdf *mlx)
{
	mlx->color->r = 250;
	mlx->color->g = 0;
	mlx->color->b = 250;
	if (mlx->pos->alt >= 0 && mlx->color->b > 0)
		mlx->color->b -= max1(mlx->pos->z, mlx->pos->zl) / 2;
	if (mlx->pos->alt < 0 && mlx->color->r > 0)
		mlx->color->r -= max1(mlx->pos->z, mlx->pos->zl) / 2;
	return ((mlx->color->r << 16) | (mlx->color->g << 8) | mlx->color->b);
}

void	is_color(t_fdf *mlx)
{
	if (mlx->pos->z != 0 || mlx->pos->zl != 0)
		mlx->pos->line_color = is_rgb(mlx);
	else
		mlx->pos->line_color = 0xffffff;
}

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
		is_color(mlx);
		my_mlx_pixel_put(mlx->img, x, y, mlx->pos->line_color);
		x += mlx->pos->x_step;
		y += mlx->pos->y_step;
	}
}

void	z2_color(t_fdf *mlx, char **tmp, int x)
{
	char	**tab;

	tab = ft_split(tmp[x], ',');
	mlx->pos->z = ft_atoi(tab[0]) * mlx->pos->alt;
	mlx->pos->line_color = ft_atoi_base(tab[1] + 2, 16) * mlx->pos->alt;
	ft_free_tab(tab);
}

void	z2l_color(t_fdf *mlx, int x, char **tmp)
{
	char	**tab;

	tab = ft_split(tmp[x], ',');
	mlx->pos->zl = ft_atoi(tab[0]) * mlx->pos->alt;
	mlx->pos->line_color = ft_atoi_base(tab[1] + 2, 16);
	ft_free_tab(tab);
}

void	calcule_z_2(t_fdf *mlx, int x, int y)
{
	char	**tmp;

	tmp = NULL;
	if (y + 1 < mlx->len->larg && ft_strchr(mlx->len->lat[x], ',') != NULL)
	{
		z2_color(mlx, tmp, x);
		ft_free_tab(tmp);
	}
	else
	{
		mlx->pos->z = ft_atoi(mlx->len->lat[x]) * mlx->pos->alt;
	}
	if (y + 1 < mlx->len->larg)
	{
		tmp = ft_split(mlx->len->map[y + 1], ' ');
		if (tmp != NULL && ft_strchr(tmp[x], ',') != NULL)
			z2l_color(mlx, x, tmp);
		else
		{
			tmp = ft_split(mlx->len->map[y + 1], ' ');
			mlx->pos->zl = ft_atoi(tmp[x]) * mlx->pos->alt;
		}
		ft_free_tab(tmp);
	}
}

void	z1_color(t_fdf *mlx, int x)
{
	char	**tab;

	tab = ft_split(mlx->len->lat[x], ',');
	mlx->pos->z = ft_atoi(tab[0]) * mlx->pos->alt;
	mlx->pos->line_color = ft_atoi_base(tab[1] + 2, 16);
	ft_free_tab(tab);
}

void	zl1_pos(t_fdf *mlx, int x)
{
	char	**tab;

	tab = NULL;
	if (x > 0)
	{
		tab = ft_split(mlx->len->lat[x - 1], ',');
		mlx->pos->zl = ft_atoi(tab[0]) * mlx->pos->alt;
		mlx->pos->line_color = ft_atoi_base(tab[1] + 2, 16);
		ft_free_tab(tab);
	}
	else if (x == 0)
	{
		tab = ft_split(mlx->len->lat[x + 1], ',');
		mlx->pos->zl = ft_atoi(tab[0]) * mlx->pos->alt;
		mlx->pos->line_color = ft_atoi_base(tab[1] + 2, 16);
		ft_free_tab(tab);
	}
}

void	calcule_z_1(t_fdf *mlx, int x)
{
	if (ft_strchr(mlx->len->lat[x], ',') != NULL)
		z1_color(mlx, x);
	else
	{
		mlx->pos->z = ft_atoi(mlx->len->lat[x]) * mlx->pos->alt;
	}
	if (x > 0)
	{
		if (ft_strchr(mlx->len->lat[x - 1], ',') != NULL)
			zl1_pos(mlx, x);
		else
		{
			mlx->pos->zl = ft_atoi(mlx->len->lat[x - 1]) * mlx->pos->alt;
		}
	}
	else if (x == 0)
	{
		if (ft_strchr(mlx->len->lat[x + 1], ',') != NULL)
			zl1_pos(mlx, x);
		else
		{
			mlx->pos->zl = ft_atoi(mlx->len->lat[x + 1]) * mlx->pos->alt;
		}
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
