/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 10:57:41 by tsishika          #+#    #+#             */
/*   Updated: 2024/03/20 01:22:46 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

unsigned int	*get_pixel_color(t_texture *texture, int y, int x)
{
	char	*dst;

	dst = texture->addr
		+ (y * texture->size_line + x * (texture->bits_per_pixel / 8));
	return ((unsigned int *)dst);
}
