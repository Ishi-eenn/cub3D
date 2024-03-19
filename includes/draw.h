/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 16:11:24 by tsishika          #+#    #+#             */
/*   Updated: 2024/03/20 04:29:45 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_H
# define DRAW_H

# include "ray.h"
# include "hook.h"
# include "struct.h"
# include "utils.h"

# include "mlx.h"

# define WALL_COLOR 0x00FF00
# define FLOOR_COLOR 0x0000FF
# define PLAYER_COLOR 0xFF0000
# define BACKGROUND 0xFFFFFF
# define PIXEL 64
# define NORTH_INDEX 3
# define SOUTH_INDEX 2
# define WEST_INDEX 1
# define EAST_INDEX 0

// draw_texture.c
unsigned int	*get_pixel_color(t_texture *texture, int y, int x);

// draw.c
void			draw(t_data *data);

// floor_ceiling.c
void			draw_ceiling(t_data *data);
void			draw_floor(t_data *data);

// init_mlx.c
void			init_mlx(t_data *data);

// minimap.c
void			draw_minimap(t_data *data);

// my_mlx_pixel_put.c
void			my_mlx_pixel_put(t_data *data, int x, int y, int color);

// test_draw.c
void			draw_wall(t_data *data, t_wall *wall, int x);

// xpm_file_to_img.c
void			xpm_file_to_img(t_data *data,
					t_texture *texture, char *texture_path);

#endif
