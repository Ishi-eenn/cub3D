/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 20:33:16 by tsishika          #+#    #+#             */
/*   Updated: 2023/12/11 01:07:40 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	parser(t_data *data, int argc, char **argv)
{
	int	fd;

	validate_input_file(argc, argv);
	fd = open_file_descriptor_for_non_directory(argv[1]);
	process_texture_configuration(fd, data);
}
