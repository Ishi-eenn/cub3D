/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xpm_file_to_img.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 15:39:00 by tsishika          #+#    #+#             */
/*   Updated: 2024/03/19 23:29:19 by tsishika         ###   ########.fr       */
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
