/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakaiheizou <nakaiheizou@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 16:11:03 by tsishika          #+#    #+#             */
/*   Updated: 2024/03/16 16:15:17 by nakaiheizou      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

int	draw_window(t_data *data)
{
	draw_ceiling(data);
	draw_floor(data);
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
