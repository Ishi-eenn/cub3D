/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 20:33:16 by tsishika          #+#    #+#             */
/*   Updated: 2023/12/15 15:40:16 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	parser(t_data *data, int argc, char **argv)
{
	int	fd;

	validate_input_file(argc, argv);
	fd = open_file_descriptor_for_non_directory(argv[1]);
	parse_and_set_texture_path_from_fd(fd, data);
	validate_and_exit_if_not_empty(fd);
	parse_and_set_room_colors_from_fd(data, fd);
	validate_and_exit_if_not_empty(fd);
	// parse_and_set_map_from_fd(data, fd);
	close(fd);
}
