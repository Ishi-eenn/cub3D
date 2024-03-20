/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_draw.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 01:29:21 by tsishika          #+#    #+#             */
/*   Updated: 2024/03/20 04:28:11 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"
#include <math.h>

void	draw_wall(t_data *data, t_wall *wall, int x)
{
	int				tex_y;
	unsigned int	color;
	int				y;

	y = 0;
	wall->step = 1.0 * PIXEL / wall->line_height;
	wall->texture_position = (wall->draw_start
			- WINDOW_HEIGHT / 2 + wall->line_height / 2) * wall->step;
	while (y < WINDOW_HEIGHT)
	{
		if (y < wall->draw_start)
			color = data->cub->room_color->ceiling;
		else if (y < wall->draw_end)
		{
			tex_y = (int)wall->texture_position & (PIXEL - 1);
			wall->texture_position += wall->step;
			color = *get_pixel_color(&data->mlx->texture[wall->side],
					tex_y, wall->texture_x);
		}
		else
			color = data->cub->room_color->floor;
		my_mlx_pixel_put(data, x, y, color);
		y++;
	}
}
