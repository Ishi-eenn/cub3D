/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 21:20:35 by tsishika          #+#    #+#             */
/*   Updated: 2024/03/08 21:49:09 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

void	parse_and_set_map_from_fd(t_data *data, int fd)
{
	t_list	*list;

	data->cub->map = malloc(sizeof(t_map));
	if (data->cub->map == NULL)
		print_error_and_exit("Memory allocation failed.");
	list = read_lines_into_linked_list(fd);
	validate_and_set_map_properties(data, list);
	data->cub->map->map_data = list_to_string_array(list, data);
	ft_lstclear(&list, free);
}
