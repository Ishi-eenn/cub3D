/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 17:29:22 by tsishika          #+#    #+#             */
/*   Updated: 2024/03/10 21:06:30 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "map.h"
# include "libft.h"
# include "struct.h"
# include "utils.h"

# include <stdbool.h>

# define ERROR_ARGC "The number of arguments is incorrect.\n"
# define ERROR_ARGV "Incorrect file name entered.\n"

// check_closed.c
void	validate_map_walkability(t_data *data);

// file_name.c
void	validate_input_file(int argc, char **argv);

// open_file.c
int		open_file_descriptor_for_non_directory(char *file);

// parser.c
void	parser(int argc, char **argv, t_data *data);

// rgb_handling.c
int		parse_and_get_rgb_color_code(char *line);

// room_color.c
void	parse_and_set_room_colors_from_fd(t_data *data, int fd);

// texture_path.c
void	parse_and_set_texture_path_from_fd(int fd, t_data *data);

#endif
