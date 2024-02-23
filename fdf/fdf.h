/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 15:58:33 by ilyanar           #+#    #+#             */
/*   Updated: 2024/02/22 18:25:16 by ilyanar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct s_fdf
{
	void			*mlx;
	void			*mlx_win;
	struct s_pos	*pos;
	struct s_img	*img;
}	t_fdf;

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
	int	x;
	int	y;
}	t_pos;

enum
{
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

#endif
