/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 22:45:57 by tsishika          #+#    #+#             */
/*   Updated: 2024/03/18 01:14:16 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hook.h"

#include <stdio.h>

int	key_press(int keycode, t_data *data)
{
	if (keycode == 0)
		move_west(data);
	if (keycode == 1)
		move_south(data);
	if (keycode == 2)
		move_east(data);
	if (keycode == 13)
		move_north(data);
	if (keycode == 53)
	{
		mlx_clear_window(data->mlx->mlx, data->mlx->win);
		mlx_destroy_window(data->mlx->mlx, data->mlx->win);
		exit(0);
	}
	if (keycode == 123)
		rotate_counterclockwise(data);
	if (keycode == 124)
		rotate_clockwise(data);
	return (0);
}
