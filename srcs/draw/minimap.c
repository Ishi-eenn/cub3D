/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 22:21:02 by tsishika          #+#    #+#             */
/*   Updated: 2024/03/20 02:39:14 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

static void	mlx_block_put(t_data *data, int x, int y, int color)
{
	int	x_i;
	int	y_i;
	int	scale;

	x_i = 0;
	scale = data->cub->map->scale;
	while (x_i < scale)
	{
		y_i = 0;
		while (y_i < scale)
		{
			my_mlx_pixel_put(data, x * scale + x_i, y * scale + y_i, color);
			y_i++;
		}
		x_i++;
	}
}

static int	get_map_element_color(t_data *data, int x, int y)
{
	int	position_x;
	int	position_y;

	position_x = (int)data->vector->position_x;
	position_y = (int)data->vector->position_y;
	if (x == position_x && y == position_y)
		return (PLAYER_COLOR);
	else if (data->cub->map->map_data[y][x] == '1')
		return (WALL_COLOR);
	else if (data->cub->map->map_data[y][x] == '0')
		return (FLOOR_COLOR);
	else
		return (BACKGROUND);
}

static void	draw_map_element_at(t_data *data, int x, int y)
{
	mlx_block_put(data, x, y, get_map_element_color(data, x, y));
}

void	draw_minimap(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < (int)data->cub->map->height)
	{
		x = 0;
		while (x < (int)data->cub->map->width)
		{
			draw_map_element_at(data, x, y);
			x++;
		}
		y++;
	}
}
