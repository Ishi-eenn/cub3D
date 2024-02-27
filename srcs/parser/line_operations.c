/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 00:30:55 by tsishika          #+#    #+#             */
/*   Updated: 2024/02/28 00:56:19 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	truncate_at_newline(char *line)
{
	char	*newline_position;

	newline_position = ft_strchr(line, '\n');
	if (newline_position)
		*newline_position = '\0';
}

char	*get_string_after_space(char *line)
{
	char	*string_after_space;

	string_after_space = ft_strchr(line, ' ');
	if (string_after_space == NULL)
		print_error_and_exit("Input format is incorrect.");
	if (string_after_space != NULL)
		string_after_space++;
	return (string_after_space);
}

void	validate_and_exit_if_not_empty(int fd)
{
	char	*line;

	line = get_next_line(fd);
	if (line == NULL)
		print_error_and_exit("format error\n");
	if (ft_strcmp(line, "\n") != 0)
	{
		free(line);
		print_error_and_exit("format error\n");
	}
	free(line);
}
