/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 17:59:48 by tsishika          #+#    #+#             */
/*   Updated: 2024/02/28 00:56:18 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	open_file_descriptor_for_non_directory(char *file)
{
	check_and_exit_if_directory(file);
	return (open_file_and_return_descriptor(file));
}
