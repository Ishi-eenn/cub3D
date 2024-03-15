/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 22:46:43 by tsishika          #+#    #+#             */
/*   Updated: 2024/03/15 22:51:23 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOOK_H
# define HOOK_H

# include "stdlib.h"

# include "struct.h"
# include "mlx.h"

int	closed_window(t_mlx *mlx);

int	key_press(int keycode, t_data *data);

#endif
