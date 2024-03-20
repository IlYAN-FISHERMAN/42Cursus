/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 15:43:16 by ilyanar           #+#    #+#             */
/*   Updated: 2024/03/18 23:33:22 by ilyanar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft/libft.h"
#include "minilibx_macos/mlx.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/fcntl.h>

void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && y >= 0 && x < WIDTH && y < HEIGHT)
	{
		dst = data->addr + (y * data->line_length + x \
			*(data->byte_per_pixel / 8));
		*(unsigned int *)dst = color;
	}
}

void	end_draw_tuto(t_fdf *mlx)
{
	mlx_string_put(mlx->pid, mlx->pid_win, 420, 170, 0xffffff, "|");
	mlx_string_put(mlx->pid, mlx->pid_win, 50, 190, 0xffffff, "|");
	mlx_string_put(mlx->pid, mlx->pid_win, 50, 190, 0x026000, \
		"  'p' for +altitude");
	mlx_string_put(mlx->pid, mlx->pid_win, 420, 190, 0xffffff, "|");
	mlx_string_put(mlx->pid, mlx->pid_win, 50, 210, 0xffffff, "|");
	mlx_string_put(mlx->pid, mlx->pid_win, 50, 210, 0x026000, \
		"  'o' for -altitude");
	mlx_string_put(mlx->pid, mlx->pid_win, 420, 210, 0xffffff, "|");
	mlx_string_put(mlx->pid, mlx->pid_win, 50, 230, 0xffffff, "|");
	mlx_string_put(mlx->pid, mlx->pid_win, 50, 230, 0x026000, \
				"  'r' for RESET");
	mlx_string_put(mlx->pid, mlx->pid_win, 420, 230, 0xffffff, "|");
	mlx_string_put(mlx->pid, mlx->pid_win, 50, 250, 0x026000, \
				"  SUPP for -zoom");
	mlx_string_put(mlx->pid, mlx->pid_win, 420, 250, 0xffffff, "|");
	mlx_string_put(mlx->pid, mlx->pid_win, 50, 250, 0xffffff, "|");
	mlx_string_put(mlx->pid, mlx->pid_win, 50, 270, 0x026000, \
				"  ENTER for +zoom");
	mlx_string_put(mlx->pid, mlx->pid_win, 420, 270, 0xffffff, "|");
	mlx_string_put(mlx->pid, mlx->pid_win, 50, 270, 0xffffff, "|");
	mlx_string_put(mlx->pid, mlx->pid_win, 50, 290, 0xffffff, \
		"+====================================+");
	mlx_string_put(mlx->pid, mlx->pid_win, 50, 170, 0x026000, \
		"  'e' for rotate +iso          ");
}

void	draw_tuto(t_fdf *mlx)
{
	mlx_string_put(mlx->pid, mlx->pid_win, 50, 50, 0xffffff, \
		"+====================================+");
	mlx_string_put(mlx->pid, mlx->pid_win, 50, 70, 0xffffff, "| ");
	mlx_string_put(mlx->pid, mlx->pid_win, 60, 70, 0x026000, \
		" 'q' or 'Left row' for left   ");
	mlx_string_put(mlx->pid, mlx->pid_win, 420, 70, 0xffffff, "|");
	mlx_string_put(mlx->pid, mlx->pid_win, 50, 90, 0xffffff, "| ");
	mlx_string_put(mlx->pid, mlx->pid_win, 50, 90, 0x026000, \
		"  'd' or 'Right row' for right ");
	mlx_string_put(mlx->pid, mlx->pid_win, 420, 90, 0xffffff, "|");
	mlx_string_put(mlx->pid, mlx->pid_win, 50, 110, 0xffffff, "| ");
	mlx_string_put(mlx->pid, mlx->pid_win, 50, 110, \
		0x026000, "  's' or 'Down row' for down   ");
	mlx_string_put(mlx->pid, mlx->pid_win, 420, 110, 0xffffff, "|");
	mlx_string_put(mlx->pid, mlx->pid_win, 50, 130, 0xffffff, "| ");
	mlx_string_put(mlx->pid, mlx->pid_win, 50, 130, 0x026000, \
		"  'w' or 'Up row' for up       ");
	mlx_string_put(mlx->pid, mlx->pid_win, 420, 130, 0xffffff, "|");
	mlx_string_put(mlx->pid, mlx->pid_win, 50, 150, 0xffffff, "| ");
	mlx_string_put(mlx->pid, mlx->pid_win, 50, 150, 0x026000, \
		"  'a' for rotate -iso          ");
	mlx_string_put(mlx->pid, mlx->pid_win, 420, 150, 0xffffff, "|");
	mlx_string_put(mlx->pid, mlx->pid_win, 50, 170, 0xffffff, "| ");
	end_draw_tuto(mlx);
}

void	reset(t_fdf *mlx)
{
	mlx->pos->beg = 50;
	mlx->pos->line_color = 0xffffff;
	mlx->pos->iso = 0.7;
	mlx->pos->alt = 1;
	mlx->pos->difx = 480;
	mlx->pos->dify = -800;
	mlx->pos->zom = -3;
	mlx->pos->yl = 0;
	mlx->pos->x = 0;
	mlx->pos->xl = 0;
	mlx->pos->yl = 0;
	mlx->pos->ra = 0;
	mlx->pos->rb = 0;
}

void	keys(t_fdf *mlx, int keycode)
{
	if (keycode == 124 || keycode == 2)
		mlx->pos->dify -= 30;
	else if (keycode == 123 || keycode == 0)
		mlx->pos->dify += 30;
	else if (keycode == 125 || keycode == 1)
		mlx->pos->difx += 30;
	else if (keycode == 126 || keycode == 13)
		mlx->pos->difx -= 30;
	else if (keycode == 12)
		mlx->pos->iso -= 0.01;
	else if (keycode == 14)
		mlx->pos->iso += 0.01;
	else if (keycode == 36 && mlx->pos->zom > -500)
		mlx->pos->zom -= 2;
	else if (keycode == 51 && mlx->pos->zom < 500)
		mlx->pos->zom += 2;
	else if (keycode == 31 && mlx->pos->alt * 10 >= -500)
		mlx->pos->alt -= 0.531415;
	else if (keycode == 35 && mlx->pos->alt * 10 <= 500)
		mlx->pos->alt += 0.531415;
	else if (keycode == 37)
	{
		mlx->pos->dify -= 30;
		mlx->pos->difx += 30;
	}
	else if (keycode == 41)
	{
		mlx->pos->dify += 30;
		mlx->pos->difx -= 30;
	}
	else if (keycode == 15)
		reset(mlx);
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
}

int	key_hooks(int keycode, t_fdf *mlx)
{
	if (keycode == 53)
		ft_printf("fdf: the window was closed\n");
	if (keycode == 53)
		freexit (mlx);
	ft_printf("key: %d\n", keycode);
	mlx_destroy_image(mlx->pid, mlx->img->img);
	mlx->img->img = mlx_new_image(mlx->pid, HEIGHT, WIDTH);
	mlx->img->addr = mlx_get_data_addr(mlx->img->img, \
		&mlx->img->byte_per_pixel, \
			&mlx->img->line_length, &mlx->img->endian);
	keys(mlx, keycode);
	draw(mlx);
	if (keycode != 4)
		mlx_string_put(mlx->pid, mlx->pid_win, 50, 50, 0xffffff, \
			"Press 'h' for help");
	mlx_string_put(mlx->pid, mlx->pid_win, 665, 20, 0xffffff, \
		"Welcome to FDF!");
	if (keycode == 4)
		draw_tuto(mlx);
	draw_numbers(mlx);
	return (1);
}

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

void	ft_first_exec(t_fdf *mlx, char **av)
{
	mlx->fd = open(av[1], O_RDONLY);
	if (mlx->fd == -1)
		ft_printf("fdf: %s: No such file or director", av[1]);
	if (mlx->fd == -1)
		freexit(mlx);
	get_lines_larg_len(mlx);
	mlx->pos->beg = 50;
	mlx->pos->line_color = 0xffffff;
	mlx->pos->iso = 0.7;
	mlx->pos->alt = 1;
	mlx->pos->difx = 480;
	mlx->pos->dify = -800;
	mlx->pos->zom = -3;
	mlx->pos->agl = 1;
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
