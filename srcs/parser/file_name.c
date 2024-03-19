/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_name.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 17:51:57 by tsishika          #+#    #+#             */
/*   Updated: 2024/03/20 01:49:41 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static bool	check_file_name(char *file_name)
{
	char	*is_dot;

	is_dot = ft_strrchr(file_name, '.');
	if (!is_dot)
		return (false);
	if (ft_strcmp(is_dot, ".cub") != 0)
		return (false);
	return (true);
}

void	validate_input_file(int argc, char **argv)
{
	if (argc != 2)
		print_error_and_exit(ERROR_ARGC);
	if (!check_file_name(argv[1]))
		return (print_error_and_exit(ERROR_ARGV));
}
