/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 21:09:25 by tsishika          #+#    #+#             */
/*   Updated: 2024/03/18 00:15:31 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static bool	is_boundary_or_space_around(t_data *data, size_t x_i, size_t y_i)
{
	char	**map;
	size_t	width;
	size_t	height;

	map = data->cub->map->map_data;
	width = data->cub->map->width - 1;
	height = data->cub->map->height - 1;
	return (x_i == 0 || y_i == 0
		|| x_i == width || y_i == height
		|| map[y_i - 1][x_i] == ' '
		|| map[y_i + 1][x_i] == ' '
		|| map[y_i][x_i - 1] == ' '
		|| map[y_i][x_i + 1] == ' ');
}

static void	find_and_init_player(t_data *data, size_t y_i, bool *player_found)
{
	size_t	x_i;

	x_i = 0;
	while (x_i < data->cub->map->width)
	{
		if (find_occurrence("NSWE", data->cub->map->map_data[y_i][x_i]))
		{
			if (*player_found)
				print_error_and_exit("Several players are present.\n");
			*player_found = true;
			if (is_boundary_or_space_around(data, x_i, y_i))
				print_error_and_exit("Player is not valid\n");
			init_vector(data, data->cub->map->map_data[y_i][x_i], x_i, y_i);
			data->cub->map->map_data[y_i][x_i] = '0';
		}
		else if (!find_occurrence("01 ", data->cub->map->map_data[y_i][x_i]))
			print_error_and_exit("Map is not valid\n");
		x_i++;
	}
}

void	scan_map_and_check_player(t_data *data)
{
	size_t	y_i;
	bool	player_found;

	y_i = 0;
	player_found = false;
	while (y_i < data->cub->map->height)
	{
		find_and_init_player(data, y_i, &player_found);
		y_i++;
	}
	if (!player_found)
		print_error_and_exit("Player is not found\n");
}
