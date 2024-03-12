/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 16:11:03 by tsishika          #+#    #+#             */
/*   Updated: 2024/03/12 16:14:35 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

void draw(t_data *data)
{
	data->mlx->mlx = mlx_init();
	data->mlx->mlx = mlx_new_window(data->mlx->mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "Cub3D");
}
