/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_closed.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 17:38:40 by tsishika          #+#    #+#             */
/*   Updated: 2024/03/10 21:06:44 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static bool	is_walkable_tile(t_data *data, size_t x_i, size_t y_i)
{
	char	**map;
	size_t	width;
	size_t	height;

	map = data->cub->map->map_data;
	width = data->cub->map->width - 1;
	height = data->cub->map->height - 1;
	return (map[y_i][x_i] == '0' &&
	(x_i == 0 || y_i == 0 ||
	x_i == width || y_i == height ||
	map[y_i - 1][x_i] == ' ' ||
	map[y_i + 1][x_i] == ' ' ||
	map[y_i][x_i - 1] == ' ' ||
	map[y_i][x_i + 1] == ' '));
}

static void	check_if_row_contains_walkable_tiles(t_data *data, size_t y_i)
{
	size_t	x_i;

	x_i = 0;
	while (x_i < data->cub->map->width)
	{
		if (is_walkable_tile(data, x_i, y_i))
			print_error_and_exit("Map is not closed or not valid\n");
		x_i++;
	}
}

void	validate_map_walkability(t_data *data)
{
	size_t	y_i;

	y_i = 0;
	while (y_i < data->cub->map->height)
	{
		check_if_row_contains_walkable_tiles(data, y_i);
		y_i++;
	}
	printf("success\n");
}
