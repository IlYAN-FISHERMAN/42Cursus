/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 15:43:16 by ilyanar           #+#    #+#             */
/*   Updated: 2024/03/08 09:55:00 by ilyanar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft/libft.h"
#include "minilibx_macos/mlx.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/fcntl.h>

void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x \
		*(data->byte_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	close_key(int keycode, t_fdf *mlx)
{
	if (keycode == 53)
	{
		ft_printf("fdf: the window was closed\n");
		freexit (mlx);
	}
	else
		ft_printf("key: %d\n", keycode);
	return (1);
}

void	ft_strerror(int ac, char **av)
{
	if (ac != 2)
	{
		ft_printf("fdf: ./fdf <*.fdf>\n");
		exit(EXIT_FAILURE);
	}
	if ((ft_strchr(av[1], '.')) \
		&& (ft_strncmp(ft_strchr(av[1], '.'), ".fdf", 5) != 0))
	{
		ft_printf("fdf: bad format file\nOnly .fdf file accepted\n");
		exit(EXIT_FAILURE);
	}
}

int	mouse_hook(int keycode, t_fdf *mlx)
{
	(void)mlx;
	if (keycode == 1)
		ft_printf("tg :D !\n");
	if (keycode == 2)
		ft_printf("tg encore plus :D !\n");
	if (keycode == 4)
		ft_printf("raph tg aussi :D !\n");
	if (keycode == 5)
		ft_printf("maria je te bolosse a smash mais pas de tg :D !\n");
	return (1);
}

void	ft_first_exec(t_fdf *mlx, char **av)
{
	mlx->fd = open(av[1], O_RDONLY);
	if (mlx->fd == -1)
		freexit(mlx);
	get_lines_larg_len(mlx);
	mlx->pos->zoom = 20;
	mlx->pos->line_color = 0xffffff;
	draw(mlx);
	mlx_put_image_to_window(mlx->pid, mlx->pid_win, mlx->img->img, 0, 0);
}

int	main(int ac, char **av)
{
	t_fdf	mlx;

	ft_strerror(ac, av);
	conf_win(&mlx);
	ft_first_exec(&mlx, av);
	mlx_hook(mlx.pid_win, 17, 0, close_win, &mlx);
	mlx_hook(mlx.pid_win, 2, 0, close_key, &mlx);
	mlx_hook(mlx.pid_win, 4, 0, mouse_hook, &mlx);
	mlx_loop(mlx.pid);
	close(mlx.fd);
}
