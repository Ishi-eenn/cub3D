/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 16:11:03 by tsishika          #+#    #+#             */
/*   Updated: 2024/03/12 16:24:00 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

void draw(t_data *data)
{
	data->mlx->mlx = mlx_init();
	if (!data->mlx->mlx)
		print_error_and_exit("mlx_init failed\n");
	data->mlx->win = mlx_new_window(data->mlx->mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "Cub3D");
	if (!data->mlx->win)
		print_error_and_exit("mlx_new_window failed\n");
	// その他のmlx系の初期化
	// mlx_loop_hookとかで描画
	// mlx_hookとかでイベント処理
	mlx_loop(data->mlx->mlx);
}
