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

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->size_line + x * (img->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void draw_map(t_data *data)
{
	size_t	x;
	size_t	y;

	y = 0;
	while (y < data->cub->map->height)
	{
		x = 0;
		while (x < data->cub->map->width)
		{
			if (data->cub->map->map_data[y][x] == '1')
				my_mlx_pixel_put(&data->mlx->img, x, y, 0x00FF0000);
			else if (data->cub->map->map_data[y][x] == '0')
				my_mlx_pixel_put(&data->mlx->img, x, y, 0x000000FF);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx->mlx, data->mlx->win, data->mlx->img.img_ptr, 0, 0);
}
	// その他のmlx系の初期化
	// mlx_loop_hookとかで描画
	// mlx_hookとかでイベント処理
void	draw(t_data *data)
{
	init_mlx(data);
	mlx_hook(data->mlx->win, 2, 1L << 0, key_press, data);
	draw_map(data);
	mlx_hook(data->mlx->win, 17, 0, closed_window, data->mlx);
	mlx_loop(data->mlx->mlx);
}
