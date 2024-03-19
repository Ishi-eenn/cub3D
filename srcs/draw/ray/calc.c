/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 15:59:11 by tsishika          #+#    #+#             */
/*   Updated: 2024/03/20 01:40:00 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

static double	title11(t_data *data, t_ray *ray)
{
	if (ray->side == 0 || ray->side == 1)
	{
		ray->perp_wall_dist = (ray->map_x - data->vector->position_x
				+ (1 - ray->step_x) / 2) / ray->ray_dir_x;
		return (data->vector->position_y
			+ ray->perp_wall_dist * ray->ray_dir_y);
	}
	ray->perp_wall_dist = (ray->map_y - data->vector->position_y
			+ (1 - ray->step_y) / 2) / ray->ray_dir_y;
	return (data->vector->position_x + ray->perp_wall_dist * ray->ray_dir_x);
}

void	calculate_wall_height(t_data *data, t_ray *ray, t_wall *wall)
{
	double	wall_x;

	wall_x = title11(data, ray);
	wall_x -= floor(wall_x);
	wall->line_height = (int)(WINDOW_HEIGHT / ray->perp_wall_dist);
	wall->side = ray->side;
	wall->texture_x = (int)(wall_x * (double)PIXEL);
	if ((ray->side == 0 || ray->side == 1) && ray->ray_dir_x < 0)
		wall->texture_x = PIXEL - wall->texture_x - 1;
	if ((ray->side == 2 || ray->side == 3) && ray->ray_dir_y > 0)
		wall->texture_x = PIXEL - wall->texture_x - 1;
	wall->draw_start = -wall->line_height / 2 + WINDOW_HEIGHT / 2;
	if (wall->draw_start < 0)
		wall->draw_start = 0;
	wall->draw_end = wall->line_height / 2 + WINDOW_HEIGHT / 2;
	if (wall->draw_end >= WINDOW_HEIGHT)
		wall->draw_end = WINDOW_HEIGHT - 1;
}
