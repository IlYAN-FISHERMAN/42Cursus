/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 15:58:33 by ilyanar           #+#    #+#             */
/*   Updated: 2024/03/12 21:30:12 by ilyanar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#include "libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# define WIDTH 1000
# define HEIGHT 1000

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
	float			line_color;
	int				z;
	int				beg;
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

typedef struct s_fdf
{
	int		fd;
	void	*pid;
	void	*pid_win;
	t_pos	*pos;
	t_img	*img;
	t_color	*color;
	t_len	*len;
}	t_fdf;

int		close_win(t_fdf *mlx);
int		freexit(t_fdf *mlx);
int		get_lines_larg_len(t_fdf *mlx);

void	conf_win(t_fdf *mlx);
void	alloc_all(t_fdf *mlx);
void	bresenham(float xl, float yl, t_fdf *mlx);
void	my_mlx_pixel_put(t_img *data, int x, int y, int color);
void	draw(t_fdf *mlx);

#endif
