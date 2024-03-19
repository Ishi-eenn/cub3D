/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 00:28:31 by tsishika          #+#    #+#             */
/*   Updated: 2024/03/16 16:31:01 by tsishika         ###   ########.fr       */
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
	if (ft_strncmp(line, "NO ", 3) == 0
		&& data->cub->texture_path->north == NULL)
		data->cub->texture_path->north = duplicate_texture_path(line);
	else if (ft_strncmp(line, "SO ", 3) == 0
		&& data->cub->texture_path->south == NULL)
		data->cub->texture_path->south = duplicate_texture_path(line);
	else if (ft_strncmp(line, "WE ", 3) == 0
		&& data->cub->texture_path->west == NULL)
		data->cub->texture_path->west = duplicate_texture_path(line);
	else if (ft_strncmp(line, "EA ", 3) == 0
		&& data->cub->texture_path->east == NULL)
		data->cub->texture_path->east = duplicate_texture_path(line);
	else
		print_error_and_exit("Texture input is incorrect.\n");
}

static void	init_texture_path(t_data *data)
{
	data->cub->texture_path = malloc(sizeof(t_texture_path));
	if (!data->cub->texture_path)
		print_error_and_exit("malloc error\n");
	data->cub->texture_path->north = NULL;
	data->cub->texture_path->south = NULL;
	data->cub->texture_path->west = NULL;
	data->cub->texture_path->east = NULL;
}

void	parse_and_set_texture_path_from_fd(int fd, t_data *data)
{
	int		i;
	char	*line;

	init_texture_path(data);
	i = 0;
	while (i < 4)
	{
		line = get_next_line(fd);
		if (line == NULL)
			print_error_and_exit("Not enough texture files.\n");
		parse_and_set_texture_path(data, line);
		free(line);
		i++;
	}
}
