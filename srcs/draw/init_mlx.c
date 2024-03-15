/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 15:13:32 by tsishika          #+#    #+#             */
/*   Updated: 2024/03/15 16:17:48 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

void	xpm_file_to_img(t_data *data, t_texture *texture, char *texture_path)
{
	texture->img_ptr = mlx_xpm_file_to_image(data->mlx->mlx,
			texture_path,
			&texture->width,
			&texture->height);
	if (!texture->img_ptr)
		print_error_and_exit("mlx_xpm_file_to_image failed\n");
	texture->addr = mlx_get_data_addr(texture->img_ptr,
			&texture->bits_per_pixel,
			&texture->size_line,
			&texture->endian);
}

// Copilotで出てきた順で適当に書いたから順番は後から変えるかもしれない
void	init_texture(t_data *data)
{
	xpm_file_to_img(data,
		&data->mlx->texture[0],
		data->cub->texture_path->north);
	xpm_file_to_img(data,
		&data->mlx->texture[1],
		data->cub->texture_path->south);
	xpm_file_to_img(data,
		&data->mlx->texture[2],
		data->cub->texture_path->west);
	xpm_file_to_img(data,
		&data->mlx->texture[3],
		data->cub->texture_path->east);
}

void	init_img(t_data *data)
{
	data->mlx->img->img_ptr = mlx_new_image(data->mlx->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	if (!data->mlx->img->img_ptr)
		print_error_and_exit("mlx_new_image failed\n");
	data->mlx->img->addr = mlx_get_data_addr(data->mlx->img->img_ptr,
			&data->mlx->img->bits_per_pixel,
			&data->mlx->img->size_line,
			&data->mlx->img->endian);
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
}
