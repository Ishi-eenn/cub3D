/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 22:21:02 by tsishika          #+#    #+#             */
/*   Updated: 2024/03/17 22:46:40 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

static void	mlx_block_put(t_data *data, int x, int y, int color)
{
	int	x_i;
	int	y_i;

	x_i = 0;
	while (x_i < SCALE)
	{
		y_i = 0;
		while (y_i < SCALE)
		{
			my_mlx_pixel_put(data, x * SCALE + x_i, y * SCALE + y_i, color);
			y_i++;
		}
		x_i++;
	}
}

static bool	is_player(char c)
{
	return (c == 'W' || c == 'E' || c == 'S' || c == 'N');
}

static int	get_map_element_color(t_data *data, int x, int y)
{
	if (data->cub->map->map_data[y][x] == '1')
		return (WALL_COLOR);
	else if (data->cub->map->map_data[y][x] == '0')
		return (FLOOR_COLOR);
	else if (is_player(data->cub->map->map_data[y][x]))
		return (PLAYER_COLOR);
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
