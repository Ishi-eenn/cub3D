/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 00:00:05 by tsishika          #+#    #+#             */
/*   Updated: 2024/03/18 00:47:40 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hook.h"

void move_east(t_data *data)
{
	double new_x;
	int position_y;

	new_x = data->vector->position_x + data->vector->plane_x * 1.0 / 10;
	position_y = (int)data->vector->position_y;
	if (data->cub->map->map_data[position_y][(int)new_x] == '0')
		data->vector->position_x = new_x;
}

void move_north(t_data *data)
{
	double new_y;
	int position_x;

	new_y = data->vector->position_y + data->vector->direction_y * 1.0 / 10;
	position_x = (int)data->vector->position_x;
	if (data->cub->map->map_data[(int)new_y][position_x] == '0')
		data->vector->position_y = new_y;
}

void move_west(t_data *data)
{
	double new_x;
	int position_y;

	new_x = data->vector->position_x + data->vector->plane_x * -1.0 / 10;
	position_y = (int)data->vector->position_y;
	if (data->cub->map->map_data[position_y][(int)new_x] == '0')
		data->vector->position_x = new_x;
}

void move_south(t_data *data)
{
	double new_y;
	int position_x;

	new_y = data->vector->position_y + data->vector->direction_y * -1.0 / 10;
	position_x = (int)data->vector->position_x;
	if (data->cub->map->map_data[(int)new_y][position_x] == '0')
		data->vector->position_y = new_y;
}
