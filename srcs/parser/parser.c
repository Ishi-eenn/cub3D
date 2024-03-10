/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 17:29:00 by tsishika          #+#    #+#             */
/*   Updated: 2024/03/10 22:13:11 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	parser(int argc, char **argv, t_data *data)
{
	int	fd;

	validate_input_file(argc, argv);
	fd = open_file_descriptor_for_non_directory(argv[1]);
	parse_and_set_texture_path_from_fd(fd, data);
	validate_and_exit_if_not_empty(fd);
	parse_and_set_room_colors_from_fd(data, fd);
	validate_and_exit_if_not_empty(fd);
	parse_and_set_map_from_fd(data, fd);
	close(fd);
	validate_map_walkability(data);
	title(data);
}
