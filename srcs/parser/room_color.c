/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room_color.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 02:02:10 by tsishika          #+#    #+#             */
/*   Updated: 2023/12/11 03:05:12 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static bool	validate_rgb_format(char *line)
{
	size_t	i;
	size_t	comma_count;

	i = 0;
	comma_count = 0;
	while (line[i])
	{
		while (ft_isdigit(line[i]))
			i++;
		if (line[i] == ',')
		{
			comma_count++;
			i++;
		}
		else if (comma_count == 2 && line[i] == '\0')
			return (true);
		else
			return (false);
	}
	return (false);
}

static bool	validate_rgb_array(char **rgb)
{
	size_t	i;

	i = 0;
	while (rgb[i])
	{
		if (is_atoi_overflow(rgb[i]) || is_rgb_overflow(rgb[i]))
			return (false);
		i++;
	}
	return (true);
}

static int	parse_and_get_rgb_color_code(char *line)
{
	char	**split;
	char	*str;

	str = get_string_after_space(line);
	if (!validate_rgb_format(str))
		print_error_and_exit("RGB format is incorrect.");
	split = ft_split(str, ',');
	if (!split)
		print_error_and_exit("malloc error\n");
	if (!validate_rgb_array(split))
		print_error_and_exit("RGB values are out of range.");
	return (ft_atoi(split[0]) << 16
		| ft_atoi(split[1]) << 8 | ft_atoi(split[2]));
}

static void	parse_and_set_room_color(t_data *data, char *line)
{
	truncate_at_newline(line);
	if (ft_strncmp(line, "F ", 2) == 0)
		data->room_color->floor = parse_and_get_rgb_color_code(line);
	else if (ft_strncmp(line, "C ", 2) == 0)
		data->room_color->ceiling = parse_and_get_rgb_color_code(line);
	else
		print_error_and_exit("room color input is incorrect.");
}

void	parse_and_set_room_colors_from_fd(t_data *data, int fd)
{
	size_t	i;
	char	*line;

	data->room_color = malloc(sizeof(t_room_color));
	if (!data->room_color)
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
