/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 15:58:33 by ilyanar           #+#    #+#             */
/*   Updated: 2024/03/21 08:17:05 by ilyanar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#include "libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# define WIDTH 1500
# define HEIGHT 1500

typedef struct s_img
{
	void			*img;
	char			*addr;
	int				byte_per_pixel;
	int				line_length;
	int				endian;
}	t_img;

typedef struct s_pos
{
	float			x_step;
	float			y_step;
	float			x;
	float			xl;
	float			y;
	float			yl;
	int				line_color;
	float			iso;
	float			zom;
	float			alt;
	float			agl;
	int				z;
	int				ra;
	int				rb;
	int				zl;
	int				beg;
	int				difx;
	int				dify;
	int				sep;
}	t_pos;

typedef struct s_len
{
	int		lon;
	int		larg;
	char	**map;
	char	**lat;
}	t_len;

typedef struct s_color
{
	int	t;
	int	r;
	int	g;
	int	b;
}	t_color;

typedef struct s_point3d
{
	float	x;
	float	y;
	float	z;
}	t_3d;

typedef struct s_fdf
{
	int		fd;
	void	*pid;
	void	*pid_win;
	t_pos	*pos;
	t_img	*img;
	t_color	*color;
	t_len	*len;
	t_3d	*tree_d;
}	t_fdf;

void	get_lines_larg_len(t_fdf *mlx);
void	ft_strerror(int ac, char **av);
void	ft_first_exec(t_fdf *mlx, char **av);
void	is_rgb(t_fdf *mlx);
void	z2_color(t_fdf *mlx, char *tmp);
void	z2l_color(t_fdf *mlx, int x, char **tmp);
void	z1_color(t_fdf *mlx, int x);
void	zl1_color(t_fdf *mlx, int x);
void	conf_win(t_fdf *mlx);
void	alloc_all(t_fdf *mlx);
void	end_draw_tuto(t_fdf *mlx);
void	draw_tuto(t_fdf *mlx);
void	draw_numbers(t_fdf *mlx);
void	draw_numbers2(t_fdf *mlx);
void	draw_numbers3(t_fdf *mlx);
void	my_mlx_pixel_put(t_img *data, int x, int y, int color);
void	next_line(t_fdf *mlx, int y);
void	draw(t_fdf *mlx);
void	calcule_z_2(t_fdf *mlx, int x, int y);
void	calcule_z_1(t_fdf *mlx, int x);
void	reset(t_fdf *mlx);
void	keys(t_fdf *mlx, int keycode);
void	isometric(float *x, float *y, int z, t_fdf *mlx);
void	bresenham(float xl, float yl, t_fdf *mlx);
void	rotate(float x, float y, t_fdf *mlx);

char	*joint_line(char *s1, char *s2);

int		freexit(t_fdf *mlx);
int		close_win(t_fdf *mlx);
int		key_hooks(int keycode, t_fdf *mlx);

float	max1(float a, float b);
float	min1(float a, float b);
float	mod(float i);

#endif
