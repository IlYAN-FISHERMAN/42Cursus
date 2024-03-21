/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 17:50:47 by ilyanar           #+#    #+#             */
/*   Updated: 2024/03/21 21:51:03 by ilyanar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft/libft.h"
#include <stdio.h>
#include "minilibx_macos/mlx.h"
#include <stdlib.h>
#include <sys/fcntl.h>

void	ft_strerror(int ac, char **av)
{
	if (ac != 2)
	{
		ft_printf("fdf: ./fdf <*.fdf>\n");
		exit(EXIT_FAILURE);
	}
	if ((ft_strchr(av[1], '.') == NULL) \
		|| (ft_strncmp(ft_strchr(av[1], '.'), ".fdf", 5) != 0))
	{
		ft_printf("fdf: bad format file\nOnly .fdf file accepted\n");
		exit(EXIT_FAILURE);
	}
}

void	configure_numbers(t_fdf *mlx)
{
	mlx->pos->beg = 50;
	mlx->pos->line_color = 0xffffff;
	mlx->pos->iso = 0.7;
	mlx->pos->alt = 1;
	mlx->pos->difx = 480;
	mlx->pos->dify = -800;
	mlx->pos->zom = -3;
	mlx->pos->agl = 1;
	mlx->color->r = 250;
	mlx->color->g = 0;
	mlx->color->b = 250;
	mlx->tree_d->angle_y = 0.0;
	mlx->tree_d->angle_x = 0.0;
}

void	ft_first_exec(t_fdf *mlx, char **av)
{
	mlx->fd = open(av[1], O_RDONLY);
	if (mlx->fd == -1)
		ft_printf("fdf: %s: No such file or director", av[1]);
	if (mlx->fd == -1)
		freexit(mlx);
	get_lines_larg_len(mlx);
	configure_numbers(mlx);
	draw(mlx);
	draw_numbers(mlx);
	mlx_string_put(mlx->pid, mlx->pid_win, 50, 50, 0xffffff, \
		"Press 'h' for help");
	mlx_string_put(mlx->pid, mlx->pid_win, 665, 20, 0xffffff, \
		"Welcome to FDF!");
}

int	main(int ac, char **av)
{
	t_fdf	mlx;

	ft_strerror(ac, av);
	conf_win(&mlx);
	ft_first_exec(&mlx, av);
	mlx_hook(mlx.pid_win, 17, 0, close_win, &mlx);
	mlx_hook(mlx.pid_win, 2, 0, key_hooks, &mlx);
	mlx_loop(mlx.pid);
	freexit(&mlx);
}
