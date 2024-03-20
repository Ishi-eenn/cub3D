/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 15:48:18 by tsishika          #+#    #+#             */
/*   Updated: 2024/03/20 01:40:01 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"

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
