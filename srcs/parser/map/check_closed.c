/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_closed.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 17:38:40 by tsishika          #+#    #+#             */
/*   Updated: 2024/03/10 18:05:27 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

bool	title3(t_data *data, size_t x_i, size_t y_i)
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

void	title2(t_data *data, size_t y_i)
{
	size_t	x_i;

	x_i = 0;
	while (x_i < data->cub->map->width)
	{
		if (title3(data, x_i, y_i))
			print_error_and_exit("Map is not closed or not valid\n");
		x_i++;
	}
}

void	title(t_data *data)
{
	size_t	y_i;

	y_i = 0;
	while (y_i < data->cub->map->height)
	{
		title2(data, y_i);
		y_i++;
	}
}
