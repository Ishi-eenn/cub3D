/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 10:57:41 by tsishika          #+#    #+#             */
/*   Updated: 2024/03/19 21:53:39 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

unsigned int	*get_pixel_color(t_texture *texture, int y, int x)
{
	char	*dst;

	dst = texture->addr + (y + texture->size_line + x * (texture->bits_per_pixel / 8));
	return ((unsigned int *)dst);
}

unsigned int	title2(t_data *data, t_ray *ray, t_wall *wall, int x)
{
	double			step;
	double			tex_pos;
	int				tex_y;
	unsigned int	*color;
	int				pixel = 16;
	(void)ray;

	step = 1.0 * pixel / wall->line_height;
	tex_pos = (wall->draw_start - WINDOW_HEIGHT / 2 + wall->line_height / 2) * step;
	tex_y = (int)tex_pos & (pixel - 1);
	color = get_pixel_color(&data->mlx->texture[wall->side], tex_y, x);
	return (*color);
}
