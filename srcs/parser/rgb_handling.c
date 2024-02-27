/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb_handling.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 16:04:39 by tsishika          #+#    #+#             */
/*   Updated: 2024/02/28 00:56:17 by tsishika         ###   ########.fr       */
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

static void	free_split(char **split)
{
	size_t	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

int	parse_and_get_rgb_color_code(char *line)
{
	char	**split;
	char	*str;
	int		rgb;

	str = get_string_after_space(line);
	if (!validate_rgb_format(str))
		print_error_and_exit("RGB format is incorrect.");
	split = ft_split(str, ',');
	if (!split)
		print_error_and_exit("malloc error\n");
	if (!validate_rgb_array(split))
		print_error_and_exit("RGB values are out of range.");
	rgb = combine_rgb_components(split[0], split[1], split[2]);
	free_split(split);
	return (rgb);
}
