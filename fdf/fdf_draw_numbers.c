/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 17:55:21 by ilyanar           #+#    #+#             */
/*   Updated: 2024/03/20 17:56:00 by ilyanar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx_macos/mlx.h"
#include "libft/libft.h"
#include "fdf.h"

void	draw_numbers3(t_fdf *mlx)
{
	char	*tab;

	tab = ft_itoa(mlx->tree_d->x);
	mlx_string_put(mlx->pid, mlx->pid_win, 1350, 250, mlx->pos->line_color, \
		"r  : ");
	mlx_string_put(mlx->pid, mlx->pid_win, 1418, 250, 0xffffff, tab);
	free(tab);
	tab = ft_itoa(mlx->tree_d->x);
	mlx_string_put(mlx->pid, mlx->pid_win, 1350, 270, mlx->pos->line_color, \
		"g  : ");
	mlx_string_put(mlx->pid, mlx->pid_win, 1418, 270, 0xffffff, tab);
	free(tab);
}

void	draw_numbers2(t_fdf *mlx)
{
	char	*tab;

	tab = ft_itoa(mlx->pos->yl * 0.1);
	mlx_string_put(mlx->pid, mlx->pid_win, 1350, 50, 0xffffff, "Yl   : ");
	mlx_string_put(mlx->pid, mlx->pid_win, 1418, 50, 0xffffff, tab);
	free(tab);
	tab = ft_itoa(mlx->pos->alt * 10);
	mlx_string_put(mlx->pid, mlx->pid_win, 1350, 170, 0xffffff, "alt  : ");
	mlx_string_put(mlx->pid, mlx->pid_win, 1418, 170, 0xffffff, tab);
	free(tab);
	tab = ft_itoa(mlx->pos->difx);
	mlx_string_put(mlx->pid, mlx->pid_win, 1350, 190, 0xffffff, "difx : ");
	mlx_string_put(mlx->pid, mlx->pid_win, 1418, 190, 0xffffff, tab);
	free(tab);
	tab = ft_itoa(mlx->pos->dify);
	mlx_string_put(mlx->pid, mlx->pid_win, 1350, 210, 0xffffff, "dify  : ");
	mlx_string_put(mlx->pid, mlx->pid_win, 1418, 210, 0xffffff, tab);
	free(tab);
	tab = ft_itoa(mlx->tree_d->x);
	mlx_string_put(mlx->pid, mlx->pid_win, 1350, 230, mlx->pos->line_color, \
		"x  : ");
	mlx_string_put(mlx->pid, mlx->pid_win, 1418, 230, 0xffffff, tab);
	free(tab);
	draw_numbers3(mlx);
}

void	draw_numbers(t_fdf *mlx)
{
	char	*tab;

	tab = ft_itoa(mlx->pos->zom * -1);
	mlx_string_put(mlx->pid, mlx->pid_win, 1350, 150, 0xffffff, "Zoom : ");
	mlx_string_put(mlx->pid, mlx->pid_win, 1418, 150, 0xffffff, tab);
	free(tab);
	tab = ft_itoa(mlx->pos->iso * 100);
	mlx_string_put(mlx->pid, mlx->pid_win, 1350, 70, 0xffffff, "Iso  : ");
	mlx_string_put(mlx->pid, mlx->pid_win, 1418, 70, 0xffffff, tab);
	free(tab);
	tab = ft_itoa(mlx->pos->x * 0.1);
	mlx_string_put(mlx->pid, mlx->pid_win, 1350, 90, 0xffffff, "X    : ");
	mlx_string_put(mlx->pid, mlx->pid_win, 1418, 90, 0xffffff, tab);
	free(tab);
	tab = ft_itoa(mlx->pos->y * 0.1);
	mlx_string_put(mlx->pid, mlx->pid_win, 1350, 110, 0xffffff, "Y    : ");
	mlx_string_put(mlx->pid, mlx->pid_win, 1418, 110, 0xffffff, tab);
	free(tab);
	tab = ft_itoa(mlx->pos->xl * 0.1);
	mlx_string_put(mlx->pid, mlx->pid_win, 1350, 130, 0xffffff, "Xl   : ");
	mlx_string_put(mlx->pid, mlx->pid_win, 1418, 130, 0xffffff, tab);
	free(tab);
	draw_numbers2(mlx);
}
