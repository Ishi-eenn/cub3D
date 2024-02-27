/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 01:02:43 by tsishika          #+#    #+#             */
/*   Updated: 2024/02/28 01:11:27 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static void	texture_path_free(t_texture_path *texture_path)
{
	free(texture_path->north);
	free(texture_path->south);
	free(texture_path->west);
	free(texture_path->east);
	free(texture_path);
}

static void	map_free(t_map *map)
{
	int	i;

	i = 0;
	while (map->map_data[i])
	{
		free(map->map_data[i]);
		i++;
	}
	free(map->map_data);
	free(map);
}

void	cub_free(t_cub *cub)
{
	texture_path_free(cub->texture_path);
	map_free(cub->map);
	free(cub->room_color);
}
