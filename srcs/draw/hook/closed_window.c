/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   closed_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 22:45:32 by tsishika          #+#    #+#             */
/*   Updated: 2024/03/15 22:51:01 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hook.h"

int	closed_window(t_mlx *mlx)
{
	mlx_clear_window(mlx->mlx, mlx->win);
	mlx_destroy_window(mlx->mlx, mlx->win);
	exit(0);
}
