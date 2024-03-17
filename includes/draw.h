/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 16:11:24 by tsishika          #+#    #+#             */
/*   Updated: 2024/03/17 21:39:25 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_H
# define DRAW_H

# include "hook.h"
# include "struct.h"
# include "utils.h"

# include "mlx.h"

// draw.c
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	draw(t_data *data);

void	draw_ceiling(t_data *data);
void	draw_floor(t_data *data);

void	init_mlx(t_data *data);

void	xpm_file_to_img(t_data *data, t_texture *texture, char *texture_path);

#endif
