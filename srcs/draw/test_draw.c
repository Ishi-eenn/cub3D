/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_draw.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 01:29:21 by tsishika          #+#    #+#             */
/*   Updated: 2024/03/19 23:37:40 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"
#include <math.h>

void	init_ray(t_data *data, t_ray *ray, int x)
{
	ray->camera_x = 2 * x / (double)WINDOW_WIDTH - 1;
	ray->ray_dir_x = data->vector->direction_x
		+ data->vector->plane_x * ray->camera_x;
	ray->ray_dir_y = data->vector->direction_y
		+ data->vector->plane_y * ray->camera_x;
	ray->map_x = (int)data->vector->position_x;
	ray->map_y = (int)data->vector->position_y;
	ray->delta_dist_x = fabs(1 / ray->ray_dir_x);
	ray->delta_dist_y = fabs(1 / ray->ray_dir_y);
	ray->hit = 0;
}

void	calculate_step_and_side_dist(t_data *data, t_ray *ray)
{
	if (ray->ray_dir_x < 0)
	{
		ray->step_x = -1;
		ray->side_dist_x = (data->vector->position_x - ray->map_x)
			* ray->delta_dist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist_x = (ray->map_x + 1.0 - data->vector->position_x)
			* ray->delta_dist_x;
	}
	if (ray->ray_dir_y < 0)
	{
		ray->step_y = -1;
		ray->side_dist_y = (data->vector->position_y - ray->map_y)
			* ray->delta_dist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist_y = (ray->map_y + 1.0 - data->vector->position_y)
			* ray->delta_dist_y;
	}
}

void	perform_dda(t_data *data, t_ray *ray)
{
	while (ray->hit == 0)
	{
		if (ray->side_dist_x < ray->side_dist_y)
		{
			ray->side_dist_x += ray->delta_dist_x;
			ray->map_x += ray->step_x;
			if (ray->step_x == 1)
				ray->side = 0;
			else
				ray->side = 1;
		}
		else
		{
			ray->side_dist_y += ray->delta_dist_y;
			ray->map_y += ray->step_y;
			if (ray->step_y == 1)
				ray->side = 2;
			else
				ray->side = 3;
		}
		if (data->cub->map->map_data[ray->map_y][ray->map_x] == '1')
			ray->hit = 1;
	}
}

double	title11(t_data *data, t_ray *ray)
{
	if (ray->side == 0 || ray->side == 1)
	{
		ray->perp_wall_dist = (ray->map_x - data->vector->position_x
				+ (1 - ray->step_x) / 2) / ray->ray_dir_x;
		return (data->vector->position_y + ray->perp_wall_dist * ray->ray_dir_y);
	}
	ray->perp_wall_dist = (ray->map_y - data->vector->position_y
			+ (1 - ray->step_y) / 2) / ray->ray_dir_y;
	return (data->vector->position_x + ray->perp_wall_dist * ray->ray_dir_x);
}

void	calculate_wall_height(t_data *data, t_ray *ray, t_wall *wall)
{
	double wall_x = title11(data, ray);
	int pixcel = 64;

	wall_x -= floor(wall_x);
	wall->line_height = (int)(WINDOW_HEIGHT / ray->perp_wall_dist);
	wall->side = ray->side;
	wall->texture_x = (int)(wall_x * (double)pixcel);
	if ((ray->side == 0 || ray->side == 1) && ray->ray_dir_x < 0)
		wall->texture_x = pixcel - wall->texture_x - 1;
	if ((ray->side == 2 || ray->side == 3) && ray->ray_dir_y > 0)
		wall->texture_x = pixcel - wall->texture_x - 1;
	wall->draw_start = -wall->line_height / 2 + WINDOW_HEIGHT / 2;
	if (wall->draw_start < 0)
		wall->draw_start = 0;
	wall->draw_end = wall->line_height / 2 + WINDOW_HEIGHT / 2;
	if (wall->draw_end >= WINDOW_HEIGHT)
		wall->draw_end = WINDOW_HEIGHT - 1;
}

void	draw_wall(t_data *data, t_ray *ray, t_wall *wall, int x)
{
	double	step;
	double	tex_pos;
	int		tex_y;
	unsigned int	color;
	int		pixel = 64;
	int y = 0;
	(void)ray;
	(void)x;

	step = 1.0 * pixel / wall->line_height;
	tex_pos = (wall->draw_start - WINDOW_HEIGHT / 2 + wall->line_height / 2) * step;
	while (y < WINDOW_HEIGHT)
	{
		if (y < wall->draw_start)
			color = data->cub->room_color->ceiling;
		else if (y < wall->draw_end)
		{
			tex_y = (int)tex_pos & (pixel - 1);
			tex_pos += step;
			color = *get_pixel_color(&data->mlx->texture[wall->side], tex_y, wall->texture_x);
		}
		else
			color = data->cub->room_color->floor;
		my_mlx_pixel_put(data, x, y, color);
		y++;
	}
}
