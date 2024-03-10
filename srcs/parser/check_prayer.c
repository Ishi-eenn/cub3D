/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_prayer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 21:09:25 by tsishika          #+#    #+#             */
/*   Updated: 2024/03/10 22:20:01 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	title2(t_data *data, size_t y_i, bool *player_found)
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
			init_vector(data, data->cub->map->map_data[y_i][x_i], x_i, y_i);
		}
		else if (!find_occurrence("01 ", data->cub->map->map_data[y_i][x_i]))
			print_error_and_exit("Map is not valid\n");
		x_i++;
	}
}

void	title(t_data *data)
{
	size_t	y_i;
	bool	player_found;

	y_i = 0;
	player_found = false;
	while (y_i < data->cub->map->height)
	{
		title2(data, y_i, &player_found);
		y_i++;
	}
	if (!player_found)
		print_error_and_exit("Player is not found\n");
}
