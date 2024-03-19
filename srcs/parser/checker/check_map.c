/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 21:25:23 by tsishika          #+#    #+#             */
/*   Updated: 2024/03/11 21:37:37 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	check_input_data(t_data *data)
{
	validate_map_walkability(data);
	scan_map_and_check_player(data);
}
