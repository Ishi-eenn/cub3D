/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 17:29:00 by tsishika          #+#    #+#             */
/*   Updated: 2024/02/27 18:01:16 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void parser(int argc, char *argv)
{
	int	fd;
	validate_input_file(argc, argv);
	fd = open_file_descriptor_for_non_directory(argv[1]);
}
