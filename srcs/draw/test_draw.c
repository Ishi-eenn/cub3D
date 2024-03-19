/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_draw.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 01:29:21 by tsishika          #+#    #+#             */
/*   Updated: 2024/03/20 01:43:30 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"
#include <math.h>

void	perform_dda(t_data *data, t_ray *ray)
{
	while (ray->hit == 0)
	{
		if (ray->side_dist_x < ray->side_dist_y)
		{
			ray->side_dist_x += ray->delta_dist_x;
			ray->map_x += ray->step_x;
			if (ray->step_x == 1)
				ray->side = 0;
			else
				ray->side = 1;
		}
		else
		{
			ray->side_dist_y += ray->delta_dist_y;
			ray->map_y += ray->step_y;
			if (ray->step_y == 1)
				ray->side = 2;
			else
				ray->side = 3;
		}
		if (data->cub->map->map_data[ray->map_y][ray->map_x] == '1')
			ray->hit = 1;
	}
}

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
