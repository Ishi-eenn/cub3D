/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_closed.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 17:38:40 by tsishika          #+#    #+#             */
/*   Updated: 2024/03/10 17:56:59 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

bool title3(t_data *data, size_t x, size_t y)
{
	return (data->cub->map->map_data[y][x] == '0' && (x == 0 || y == 0 || x == data->cub->map->width - 1 || y == data->cub->map->height - 1 ||
	data->cub->map->map_data[y - 1][x] == ' ' || data->cub->map->map_data[y + 1][x] == ' ' || data->cub->map->map_data[y][x - 1] == ' ' || data->cub->map->map_data[y][x + 1] == ' '));
}

void title2(t_data *data, size_t y){
	size_t	x;

	x = 0;
	while(x < data->cub->map->width){
		if (title3(data, x, y))
			print_error_and_exit("Map is not closed or not valid");
		x++;
	}
}

// void title2(t_data *data, size_t y){
// 	size_t	x;

// 	x = 0;
// 	while(x < data->cub->map->width){
// 		if (data->cub->map->map_data[y][x] == '0' && (x == 0 || y == 0 || x == data->cub->map->width - 1 || y == data->cub->map->height - 1 ||
// 		data->cub->map->map_data[y - 1][x] == ' ' || data->cub->map->map_data[y + 1][x] == ' ' || data->cub->map->map_data[y][x - 1] == ' ' || data->cub->map->map_data[y][x + 1] == ' '))
// 		print_error_and_exit("Map is not closed or not valid");
// 		x++;
// 	}
// }

void title(t_data *data){
	size_t	y;

	y = 0;
	while(y < data->cub->map->height){
		title2(data, y);
		y++;
	}
	printf("success\n");
}
