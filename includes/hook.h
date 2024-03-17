/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 22:46:43 by tsishika          #+#    #+#             */
/*   Updated: 2024/03/18 01:23:40 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOOK_H
# define HOOK_H

# include "stdlib.h"

# include "struct.h"
# include "mlx.h"

// closed_window.c
int		closed_window(t_mlx *mlx);

// key_press.c
int		key_press(int keycode, t_data *data);

// move.c
void	move_east(t_data *data);
void	move_west(t_data *data);
void	move_south(t_data *data);
void	move_north(t_data *data);

// rotate.c
void	rotate_clockwise(t_data *data);
void	rotate_counterclockwise(t_data *data);

#endif
