/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 21:20:30 by tsishika          #+#    #+#             */
/*   Updated: 2024/03/08 21:49:23 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

size_t	validate_map_length(t_list *list)
{
	size_t	len;

	len = ft_lstsize(list);
	if (len > MAX_MAP_LINE_LENGTH)
		print_error_and_exit("Map is too long.\n");
	return (len);
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
