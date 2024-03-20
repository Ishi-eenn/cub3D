/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 16:11:03 by tsishika          #+#    #+#             */
/*   Updated: 2024/03/20 04:24:03 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

int	draw_window(t_data *data)
{
	t_ray	ray;
	t_wall	wall;
	int		x_i;

	draw_ceiling(data);
	draw_floor(data);
	x_i = 0;
	while (x_i < WINDOW_WIDTH)
	{
		init_ray(data, &ray, x_i);
		calculate_step_and_side_dist(data, &ray);
		perform_dda(data, &ray);
		calculate_wall_height(data, &ray, &wall);
		draw_wall(data, &wall, x_i);
		x_i++;
	}
	if (data->mlx->map)
		draw_minimap(data);
	mlx_put_image_to_window(data->mlx->mlx,
		data->mlx->win,
		data->mlx->img.img_ptr,
		0, 0);
	return (0);
}

void	draw(t_data *data)
{
	init_mlx(data);
	mlx_loop_hook(data->mlx->mlx, &draw_window, data);
	mlx_hook(data->mlx->win, 2, 1L << 0, &key_press, data);
	mlx_hook(data->mlx->win, 4, 1L << 2, &mouse_press, data);
	mlx_hook(data->mlx->win, 5, 1L << 3, &mouse_release, data);
	mlx_hook(data->mlx->win, 6, 1L << 6, &mouse_rotate, data);
	mlx_hook(data->mlx->win, 17, 0, &closed_window, data->mlx);
	mlx_loop(data->mlx->mlx);
}
