/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 00:39:44 by tsishika          #+#    #+#             */
/*   Updated: 2023/12/11 00:53:44 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static void	truncate_at_newline(char *line)
{
	char	*newline_position;

	newline_position = ft_strchr(line, '\n');
	if (newline_position)
		*newline_position = '\0';
}

static char	*get_texture_input(char *line)
{
	char	*texture_input_ptr;

	texture_input_ptr = ft_strchr(line, ' ');
	if (texture_input_ptr == NULL)
		print_error_and_exit("Texture input is incorrect.");
	if (texture_input_ptr != NULL)
		texture_input_ptr++;
	return (texture_input_ptr);
}

static char	*duplicate_texture_input(char *line)
{
	char	*extracted_input;

	extracted_input = ft_strdup(get_texture_input(line));
	if (extracted_input == NULL)
		print_error_and_exit("malloc error");
	return (extracted_input);
}

void	parse_and_set_texture_path(t_data *data, char *line)
{
	truncate_at_newline(line);
	if (ft_strncmp(line, "NO ", 3) == 0)
		data->texture_path->north = duplicate_texture_input(line);
	else if (ft_strncmp(line, "SO ", 3) == 0)
		data->texture_path->south = duplicate_texture_input(line);
	else if (ft_strncmp(line, "WE ", 3) == 0)
		data->texture_path->west = duplicate_texture_input(line);
	else if (ft_strncmp(line, "EA ", 3) == 0)
		data->texture_path->east = duplicate_texture_input(line);
	else
		print_error_and_exit("Texture input is incorrect.");
}
