/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_name.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 20:06:38 by tsishika          #+#    #+#             */
/*   Updated: 2023/12/10 22:32:20 by tsishika         ###   ########.fr       */
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
