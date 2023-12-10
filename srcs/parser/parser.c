/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 20:33:16 by tsishika          #+#    #+#             */
/*   Updated: 2023/12/11 00:46:13 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	title(int fd, t_data *data)
{
	int		i;
	char	*line;

	i = 0;
	data->texture_path = malloc(sizeof(t_texture_path));
	if (data->texture_path == NULL)
		print_error_and_exit("malloc error");
	while (i < 4)
	{
		line = get_next_line(fd);
		parse_and_set_texture_path(data, line);
		free(line);
		i++;
	}
}
