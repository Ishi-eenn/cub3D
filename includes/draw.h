/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 16:11:24 by tsishika          #+#    #+#             */
/*   Updated: 2024/03/15 22:51:34 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_H
# define DRAW_H

# include "hook.h"
# include "struct.h"
# include "utils.h"

# include "mlx.h"

// draw.c
void	draw(t_data *data);

void	init_mlx(t_data *data);

void	xpm_file_to_img(t_data *data, t_texture *texture, char *texture_path);

#endif
