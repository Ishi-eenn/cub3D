/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 00:51:45 by tsishika          #+#    #+#             */
/*   Updated: 2024/03/18 01:18:47 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hook.h"
#include <math.h>

static void	rotate_vector(t_data *data, double rotation_speed)
{
	double old_direction_x;
	double old_plane_x;

	old_direction_x= data->vector->direction_x;
	data->vector->direction_x = data->vector->direction_x * cos(rotation_speed) - data->vector->direction_y * sin(rotation_speed);
	data->vector->direction_y = old_direction_x * sin(rotation_speed) + data->vector->direction_y * cos(rotation_speed);
	old_plane_x = data->vector->plane_x;
	data->vector->plane_x = data->vector->plane_x * cos(rotation_speed) - data->vector->plane_y * sin(rotation_speed);
	data->vector->plane_y = old_plane_x * sin(rotation_speed) + data->vector->plane_y * cos(rotation_speed);
}

void	rotate_clockwise(t_data *data)
{
	rotate_vector(data, 0.1);
}

void	rotate_counterclockwise(t_data *data)
{
	rotate_vector(data, -0.1);
}
