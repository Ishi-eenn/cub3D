/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 00:28:31 by tsishika          #+#    #+#             */
/*   Updated: 2024/02/28 00:56:13 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static char	*duplicate_texture_path(char *line)
{
	char	*extracted_input;

	extracted_input = ft_strdup(get_string_after_space(line));
	if (extracted_input == NULL)
		print_error_and_exit("malloc error");
	return (extracted_input);
}

static void	parse_and_set_texture_path(t_data *data, char *line)
{
	truncate_at_newline(line);
	if (ft_strncmp(line, "NO ", 3) == 0)
		data->cub->texture_path->north = duplicate_texture_path(line);
	else if (ft_strncmp(line, "SO ", 3) == 0)
		data->cub->texture_path->south = duplicate_texture_path(line);
	else if (ft_strncmp(line, "WE ", 3) == 0)
		data->cub->texture_path->west = duplicate_texture_path(line);
	else if (ft_strncmp(line, "EA ", 3) == 0)
		data->cub->texture_path->east = duplicate_texture_path(line);
	else
		print_error_and_exit("Texture input is incorrect.");
}

void	parse_and_set_texture_path_from_fd(int fd, t_data *data)
{
	int		i;
	char	*line;

	data->cub->texture_path = malloc(sizeof(t_texture_path));
	if (!data->cub->texture_path)
		print_error_and_exit("malloc error");
	i = 0;
	while (i < 4)
	{
		line = get_next_line(fd);
		parse_and_set_texture_path(data, line);
		free(line);
		i++;
	}
}
