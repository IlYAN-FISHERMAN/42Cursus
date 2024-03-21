/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 17:21:24 by ilyanar           #+#    #+#             */
/*   Updated: 2024/03/21 16:55:25 by ilyanar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft/libft.h"

void	is_rgb(t_fdf *mlx)
{
	if (mlx->pos->z != 0 || mlx->pos->zl != 0)
	{
		mlx->color->r = 250;
		mlx->color->g = 0;
		mlx->color->b = 250;
		if ((mlx->pos->z > 0 || mlx->pos->zl > 0) && mlx->color->b > 10)
			mlx->color->b -= max1(mlx->pos->z, mlx->pos->zl) / 2;
		if ((mlx->pos->z < 0 || mlx->pos->zl < 0) && mlx->color->r > 10)
			mlx->color->r += max1(mlx->pos->z, mlx->pos->zl) / 2;
		mlx->pos->line_color = ((mlx->color->r << 16) | \
			(mlx->color->g << 8) | mlx->color->b);
	}
	else
		mlx->pos->line_color = 0xffffff;
}

void	z2_color(t_fdf *mlx, char *tmp)
{
	char	**tab;

	tab = ft_split(tmp, ',');
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

void	z1_color(t_fdf *mlx, int x)
{
	char	**tab;

	tab = ft_split(mlx->len->lat[x], ',');
	mlx->pos->z = ft_atoi(tab[0]) * mlx->pos->alt;
	mlx->pos->line_color = ft_atoi_base(tab[1] + 2, 16);
	ft_free_tab(tab);
}

void	zl1_color(t_fdf *mlx, int x)
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
