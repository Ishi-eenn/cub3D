/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 20:13:27 by tsishika          #+#    #+#             */
/*   Updated: 2023/12/15 16:05:37 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "stdbool.h"
# include "stdio.h"

# include "utils.h"
# include "libft.h"
# include "structures.h"

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
void	parser(t_data *data, int argc, char **argv);

// rgb_handling.c
int	parse_and_get_rgb_color_code(char *line);

// room_colors.c
void	parse_and_set_room_colors_from_fd(t_data *data, int fd);

// texture_path.c
void	parse_and_set_texture_path_from_fd(int fd, t_data *data);

#endif
