/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 21:20:37 by tsishika          #+#    #+#             */
/*   Updated: 2024/03/08 21:29:25 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

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
