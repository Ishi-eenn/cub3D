/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map_data.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 22:07:15 by tsishika          #+#    #+#             */
/*   Updated: 2024/03/08 22:33:42 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

static char	*fill_string_to_width(t_data *data, char *line)
{
	size_t	len;
	size_t	diff;
	char	*fill;

	len = ft_strlen(line);
	diff = data->cub->map->width - len;
	fill = malloc(sizeof(char) * (diff + 1));
	if (fill == NULL)
		print_error_and_exit("malloc failed");
	ft_memset(fill, ' ', diff);
	fill[diff] = '\0';
	return (fill);
}

static char	*align_string_with_width(t_data *data, char *line)
{
	char	*fill;
	char	*aligned_string;

	fill = fill_string_to_width(data, line);
	aligned_string = ft_strjoin(line, fill);
	if (aligned_string == NULL)
		print_error_and_exit("malloc failed");
	free(fill);
	return (aligned_string);
}

char	**convert_list_to_aligned_string_array(t_list *list, t_data *data)
{
	char	**map;
	size_t	i;

	map = malloc(sizeof(char *) * (data->cub->map->height + 1));
	if (map == NULL)
		print_error_and_exit("malloc failed");
	i = 0;
	while (list)
	{
		map[i] = align_string_with_width(data, (char *)list->content);
		list = list->next;
		i++;
	}
	map[i] = NULL;
	return (map);
}
