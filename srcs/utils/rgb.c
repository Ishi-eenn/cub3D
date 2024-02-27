/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 15:55:49 by tsishika          #+#    #+#             */
/*   Updated: 2024/02/28 00:54:36 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	combine_rgb_components(char *red, char *green, char *blue)
{
	return (ft_atoi(red) << 16 | ft_atoi(green) << 8 | ft_atoi(blue));
}
