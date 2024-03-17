/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 16:11:24 by tsishika          #+#    #+#             */
/*   Updated: 2024/03/17 22:46:01 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_H
# define DRAW_H

# include "hook.h"
# include "struct.h"
# include "utils.h"

# include "mlx.h"

// minimap
# define WALL_COLOR 0x00FF00
# define FLOOR_COLOR 0x0000FF
# define PLAYER_COLOR 0xFF0000
# define BACKGROUND 0xFFFFFF
# define SCALE 10

// draw.c
void	draw(t_data *data);

// floor_ceiling.c
void	draw_ceiling(t_data *data);
void	draw_floor(t_data *data);

// init_mlx.c
void	init_mlx(t_data *data);

// minimap.c
void	draw_minimap(t_data *data);

// my_mlx_pixel_put.c
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);

// xpm_file_to_img.c
void	xpm_file_to_img(t_data *data, t_texture *texture, char *texture_path);

#endif
