/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 17:29:22 by tsishika          #+#    #+#             */
/*   Updated: 2024/02/28 01:11:58 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "libft.h"
# include "struct.h"
# include "utils.h"

# include <stdbool.h>

# define ERROR_ARGC "The number of arguments is incorrect.\n"
# define ERROR_ARGV "Incorrect file name entered.\n"

# define MAX_MAP_LINE_LENGTH 200

// file_name.c
void	validate_input_file(int argc, char **argv);

// line_operations.c
void	truncate_at_newline(char *line);
char	*get_string_after_space(char *line);
void	validate_and_exit_if_not_empty(int fd);

// map.c
void	parse_and_set_map_from_fd(t_data *data, int fd);

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
