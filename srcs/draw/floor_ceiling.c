/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor_ceiling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 21:31:45 by tsishika          #+#    #+#             */
/*   Updated: 2024/03/17 21:50:33 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

void	draw_floor(t_data *data)
{
	int	x_i;
	int	y_i;

	y_i = WINDOW_HEIGHT / 2;
	while (y_i < WINDOW_HEIGHT)
	{
		x_i = 0;
		while (x_i < WINDOW_WIDTH)
		{
			my_mlx_pixel_put(data, x_i, y_i, data->cub->room_color->floor);
			x_i++;
		}
		y_i++;
	}
}

void	draw_ceiling(t_data *data)
{
	int	x_i;
	int	y_i;

	y_i = 0;
	while (y_i < WINDOW_HEIGHT / 2)
	{
		x_i = 0;
		while (x_i < WINDOW_WIDTH)
		{
			my_mlx_pixel_put(data, x_i, y_i, data->cub->room_color->ceiling);
			x_i++;
		}
		y_i++;
	}
}
