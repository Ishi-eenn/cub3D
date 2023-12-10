/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 22:31:28 by tsishika          #+#    #+#             */
/*   Updated: 2023/12/10 23:13:54 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	open_file_descriptor_for_non_directory(char *file)
{
	check_and_exit_if_directory(file);
	return (open_file_and_return_descriptor(file));
}
