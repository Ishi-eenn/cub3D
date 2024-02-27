/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_overflow.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 02:31:11 by tsishika          #+#    #+#             */
/*   Updated: 2024/02/28 00:54:47 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

bool	is_atoi_overflow(char *line)
{
	long	n;

	n = ft_strtol(line);
	if (n > INT_MAX || n < INT_MIN)
		return (true);
	return (false);
}

bool	is_rgb_overflow(char *rgb)
{
	int	n;

	n = ft_atoi(rgb);
	if (n > 255 || n < 0)
		return (true);
	return (false);
}
