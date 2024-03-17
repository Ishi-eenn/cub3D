/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 16:11:03 by tsishika          #+#    #+#             */
/*   Updated: 2024/03/18 00:16:15 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

#include <math.h>

void init_ray(t_data *data, t_ray *ray, int x)
{
	ray->camera_x = 2 * x / (double)WINDOW_WIDTH - 1;
	ray->ray_dir_x = data->vector->direction_x + data->vector->plane_x * ray->camera_x;
	ray->ray_dir_y = data->vector->direction_y + data->vector->plane_y * ray->camera_x;
	ray->map_x = (int)data->vector->position_x;
	ray->map_y = (int)data->vector->position_y;
	ray->delta_dist_x = fabs(1 / ray->ray_dir_x);
	ray->delta_dist_y = fabs(1 / ray->ray_dir_y);
	ray->hit = 0;
}

void calculate_step_and_side_dist(t_data *data, t_ray *ray)
{
	if (ray->ray_dir_x < 0)
	{
		ray->step_x = -1;
		ray->side_dist_x = (data->vector->position_x - ray->map_x) * ray->delta_dist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist_x = (ray->map_x + 1.0 - data->vector->position_x) * ray->delta_dist_x;
	}
	if (ray->ray_dir_y < 0)
	{
		ray->step_y = -1;
		ray->side_dist_y = (data->vector->position_y - ray->map_y) * ray->delta_dist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist_y = (ray->map_y + 1.0 - data->vector->position_y) * ray->delta_dist_y;
	}
}

void perform_dda(t_data *data, t_ray *ray)
{
	while (ray->hit == 0)
	{
		if (ray->side_dist_x < ray->side_dist_y)
		{
			ray->side_dist_x += ray->delta_dist_x;
			ray->map_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->side_dist_y += ray->delta_dist_y;
			ray->map_y += ray->step_y;
			ray->side = 1;
		}
		if (data->cub->map->map_data[ray->map_y][ray->map_x] == '1')
			ray->hit = 1;
	}
}

void calculate_wall_height(t_data *data, t_ray *ray, t_wall *wall)
{
	if (ray->side == 0)
		wall->perp_wall_dist = (ray->map_x - data->vector->position_x + (1 - ray->step_x) / 2) / ray->ray_dir_x;
	else
		wall->perp_wall_dist = (ray->map_y - data->vector->position_y + (1 - ray->step_y) / 2) / ray->ray_dir_y;
	wall->line_height = (int)(WINDOW_HEIGHT / wall->perp_wall_dist);
	wall->draw_start = -wall->line_height / 2 + WINDOW_HEIGHT / 2;
	if (wall->draw_start < 0)
		wall->draw_start = 0;
	wall->draw_end = wall->line_height / 2 + WINDOW_HEIGHT / 2;
	if (wall->draw_end >= WINDOW_HEIGHT)
		wall->draw_end = WINDOW_HEIGHT - 1;
}

void draw_wall(t_data *data, t_wall *wall, int x)
{
	int	y;

	y = 0;
	while (y < wall->draw_start)
	{
		my_mlx_pixel_put(data, x, y, data->cub->room_color->ceiling);
		y++;
	}
	while (y < wall->draw_end)
	{
		my_mlx_pixel_put(data, x, y, 0x000000);
		y++;
	}
	while (y < WINDOW_HEIGHT)
	{
		my_mlx_pixel_put(data, x, y, data->cub->room_color->floor);
		y++;
	}
}

int	draw_window(t_data *data)
{
	t_ray	ray;
	t_wall	wall;
	int		x = 0;

	draw_ceiling(data);
	draw_floor(data);

	while (x < WINDOW_WIDTH)
	{
		init_ray(data, &ray, x);
		calculate_step_and_side_dist(data, &ray);
		perform_dda(data, &ray);
		calculate_wall_height(data, &ray, &wall);
		draw_wall(data, &wall, x);
		x++;
	}
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
	mlx_hook(data->mlx->win, 17, 0, &closed_window, data->mlx);
	mlx_loop(data->mlx->mlx);
}
