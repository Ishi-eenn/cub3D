/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 21:37:48 by tsishika          #+#    #+#             */
/*   Updated: 2024/03/16 12:40:50 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

static void	calculate_max_string_length_in_list(t_data *data, t_list *list)
{
	size_t	width;

	data->cub->map->width = 0;
	while (list)
	{
		width = ft_strlen(list->content);
		if (width > data->cub->map->width)
			data->cub->map->width = width;
		list = list->next;
	}
}

static void	set_map_height_in_list(t_data *data, t_list *list)
{
	data->cub->map->height = ft_lstsize(list);
}

void	validate_and_set_map_properties(t_data *data, t_list *list)
{
	calculate_max_string_length_in_list(data, list);
	set_map_height_in_list(data, list);
	if (data->cub->map->width > MAX_MAP_WIDTH)
		print_error_and_exit("Map width is too long.\n");
	if (data->cub->map->height > MAX_MAP_HEIGHT)
		print_error_and_exit("Map height is too long.\n");
}
