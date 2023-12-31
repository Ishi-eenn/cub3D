/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 20:24:40 by tsishika          #+#    #+#             */
/*   Updated: 2023/12/10 22:34:12 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	check_and_exit_if_directory(char *file)
{
	int	fd;

	fd = open(file, O_DIRECTORY);
	if (0 <= fd)
	{
		close(fd);
		print_perror_and_exit(file);
	}
}

int	open_file_and_return_descriptor(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		print_perror_and_exit(file);
	return (fd);
}
