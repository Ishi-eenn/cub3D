/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 15:13:32 by tsishika          #+#    #+#             */
/*   Updated: 2024/03/20 04:20:05 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

static void	init_texture(t_data *data)
{
	xpm_file_to_img(data,
		&data->mlx->texture[3],
		data->cub->texture_path->north);
	xpm_file_to_img(data,
		&data->mlx->texture[2],
		data->cub->texture_path->south);
	xpm_file_to_img(data,
		&data->mlx->texture[1],
		data->cub->texture_path->west);
	xpm_file_to_img(data,
		&data->mlx->texture[0],
		data->cub->texture_path->east);
}

static void	init_img(t_data *data)
{
	data->mlx->img.img_ptr = mlx_new_image(data->mlx->mlx,
			WINDOW_WIDTH,
			WINDOW_HEIGHT);
	if (!data->mlx->img.img_ptr)
		print_error_and_exit("mlx_new_image failed\n");
	data->mlx->img.addr = mlx_get_data_addr(data->mlx->img.img_ptr,
			&data->mlx->img.bits_per_pixel,
			&data->mlx->img.size_line,
			&data->mlx->img.endian);
}

void	init_mlx(t_data *data)
{
	data->mlx->mlx = mlx_init();
	if (!data->mlx->mlx)
		print_error_and_exit("mlx_init failed\n");
	data->mlx->win = mlx_new_window(data->mlx->mlx,
			WINDOW_WIDTH,
			WINDOW_HEIGHT,
			"Cub3D");
	if (!data->mlx->win)
		print_error_and_exit("mlx_new_window failed\n");
	init_texture(data);
	init_img(data);
	data->mlx->map = true;
}
