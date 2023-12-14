/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 03:26:49 by tsishika          #+#    #+#             */
/*   Updated: 2023/12/14 10:28:16 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	title(t_data *data, int	fd)
{
	size_t	i;
	char	*line;

	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break;
	}
}

void	parse_and_set_map_from_fd(t_data *data, int fd)
{
	data->map = malloc(sizeof(t_map));
	if (data->map == NULL)
		print_error_and_exit("Memory allocation failed.");
}
