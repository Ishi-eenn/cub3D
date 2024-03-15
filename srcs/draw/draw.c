/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 16:11:03 by tsishika          #+#    #+#             */
/*   Updated: 2024/03/15 15:22:02 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

int closed_window(t_mlx *mlx)
{
	mlx_clear_window(mlx->mlx, mlx->win);
	mlx_destroy_window(mlx->mlx, mlx->win);
	exit(0);
}

int key_press(int keycode, t_data *data)
{
	if (keycode == 53)
	{
		mlx_clear_window(data->mlx->mlx, data->mlx->win);
		mlx_destroy_window(data->mlx->mlx, data->mlx->win);
		exit(0);
	}
	return (0);
}

void init_mlx(t_data *data)
{
	data->mlx->mlx = mlx_init();
	if (!data->mlx->mlx)
		print_error_and_exit("mlx_init failed\n");
	data->mlx->win = mlx_new_window(data->mlx->mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "Cub3D");
	if (!data->mlx->win)
		print_error_and_exit("mlx_new_window failed\n");
}

void draw(t_data *data)
{
	init_mlx(data);

	// その他のmlx系の初期化
	// mlx_loop_hookとかで描画
	// mlx_hookとかでイベント処理

	mlx_hook(data->mlx->win, 2, 1L << 0, key_press, data);
	mlx_hook(data->mlx->win, 17, 0, closed_window, data->mlx);
	mlx_loop(data->mlx->mlx);
}
