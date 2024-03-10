/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room_color.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 00:46:36 by tsishika          #+#    #+#             */
/*   Updated: 2024/03/09 01:49:54 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static void	parse_and_set_room_color(t_data *data, char *line)
{
	truncate_at_newline(line);
	if (ft_strncmp(line, "F ", 2) == 0)
		data->cub->room_color->floor = parse_and_get_rgb_color_code(line);
	else if (ft_strncmp(line, "C ", 2) == 0)
		data->cub->room_color->ceiling = parse_and_get_rgb_color_code(line);
	else
		print_error_and_exit("room color input is incorrect.\n");
}

void	parse_and_set_room_colors_from_fd(t_data *data, int fd)
{
	size_t	i;
	char	*line;

	data->cub->room_color = malloc(sizeof(t_room_color));
	if (!data->cub->room_color)
		print_error_and_exit("malloc error\n");
	i = 0;
	while (i < 2)
	{
		line = get_next_line(fd);
		parse_and_set_room_color(data, line);
		free(line);
		i++;
	}
}
