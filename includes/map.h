/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 05:22:07 by tsishika          #+#    #+#             */
/*   Updated: 2024/03/02 05:26:14 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

#include "struct.h"

#include <stdbool.h>

// line_operations.c
void	truncate_at_newline(char *line);
char	*get_string_after_space(char *line);
void	validate_and_exit_if_not_empty(int fd);

// map.c
void	parse_and_set_map_from_fd(t_data *data, int fd);

#endif
