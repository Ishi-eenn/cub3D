/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 03:34:58 by tsishika          #+#    #+#             */
/*   Updated: 2024/03/18 04:00:00 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hook.h"

int	mouse_press(int button, int x, int y, t_data *data)
{
	(void)y;
	if (button == 1 || button == 2)
	{
		data->mlx->mouse.button = button;
		data->mlx->mouse.x = x;
	}
	return (0);
}

int	mouse_release(int button, int x, int y, t_data *data)
{
	(void)x;
	(void)y;
	(void)button;
	if (data->mlx->mouse.button == 1 || data->mlx->mouse.button == 2)
		data->mlx->mouse.button = 0;
	return (0);
}

int	mouse_rotate(int x, int y, t_data *data)
{
	(void)y;
	if (data->mlx->mouse.button == 1 || data->mlx->mouse.button == 2)
	{
		if (x - data->mlx->mouse.x > 0)
			rotate_clockwise(data);
		else if (x - data->mlx->mouse.x < 0)
			rotate_counterclockwise(data);
	}
	return (0);
}
