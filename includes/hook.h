/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 22:46:43 by tsishika          #+#    #+#             */
/*   Updated: 2024/03/18 01:13:57 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOOK_H
# define HOOK_H

# include "stdlib.h"

# include "struct.h"
# include "mlx.h"

int	closed_window(t_mlx *mlx);

int	key_press(int keycode, t_data *data);

void move_east(t_data *data);
void move_west(t_data *data);
void move_south(t_data *data);
void move_north(t_data *data);

void	rotate_clockwise(t_data *data);
void	rotate_counterclockwise(t_data *data);

#endif
