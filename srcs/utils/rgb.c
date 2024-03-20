/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 15:55:49 by tsishika          #+#    #+#             */
/*   Updated: 2024/03/20 01:50:55 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	combine_rgb_components(char *red, char *green, char *blue)
{
	return (ft_atoi(red) << 16 | ft_atoi(green) << 8 | ft_atoi(blue));
}
