/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_vector.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 21:11:39 by tsishika          #+#    #+#             */
/*   Updated: 2024/03/20 04:20:30 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	init_vector(t_data *data, char c, int x, int y)
{
	data->vector->position_x = 1.0 * x + 0.5;
	data->vector->position_y = 1.0 * y + 0.5;
	data->vector->direction_x = 1.0;
	data->vector->direction_y = 1.0;
	data->vector->plane_x = 0.66;
	data->vector->plane_y = 0.66;
	if (c == 'N' || c == 'S')
	{
		data->vector->direction_x = 0.0;
		data->vector->plane_y = 0.0;
		if (c == 'N')
			data->vector->direction_y = -1.0;
		else
			data->vector->plane_x = 1.0;
	}
	if (c == 'W' || c == 'E')
	{
		data->vector->direction_y = 0.0;
		data->vector->plane_x = 0.0;
		if (c == 'W')
		{
			data->vector->direction_x = -1.0;
			data->vector->plane_y = -1.0;
		}
	}
}
