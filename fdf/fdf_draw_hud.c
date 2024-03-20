/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw_hud.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 17:33:28 by ilyanar           #+#    #+#             */
/*   Updated: 2024/03/20 17:56:09 by ilyanar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "minilibx_macos/mlx.h"

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
