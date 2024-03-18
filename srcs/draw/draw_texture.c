/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 10:57:41 by tsishika          #+#    #+#             */
/*   Updated: 2024/03/18 11:39:34 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

unsigned int	*title(t_texture *texture, int y, int x)
{
	char	*dst;

	dst = texture->addr + (y + texture->size_line + x * (texture->bits_per_pixel / 8));
	return ((unsigned int *)dst);
}

unsigned int	title2(t_data *data, t_ray *ray, t_wall *wall, int y)
{
	double			row;
	double			col;
	t_texture		*dir;
	unsigned int	*color;

	dir = &data->mlx->texture[3];
	if (ray->side_dist_x == 0)
		col = data->vector->position_y + ray->perp_wall_dist * ray->ray_dir_y;
	else
		col = data->vector->position_x + ray->perp_wall_dist * ray->ray_dir_x;
	col = (col - (int)col) * 64;
	row = ((y - wall->draw_start + wall->perp_wall_dist) * 64 / wall->line_height);
	color = title(dir, (int)col, (int)row);
	return (*color);
}
