/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 20:13:27 by tsishika          #+#    #+#             */
/*   Updated: 2023/12/11 01:07:34 by tsishika         ###   ########.fr       */
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

// open_file.c
int		open_file_descriptor_for_non_directory(char *file);

// parser.c
void	parser(t_data *data, int argc, char **argv);

// texture_path.c
void	parse_and_set_texture_path(t_data *data, char *line);
void	process_texture_configuration(int fd, t_data *data);

#endif
