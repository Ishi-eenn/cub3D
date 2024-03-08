/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 05:22:07 by tsishika          #+#    #+#             */
/*   Updated: 2024/03/08 21:48:45 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include "struct.h"
# include "libft.h"
# include "utils.h"

# include <stdbool.h>

# define MAX_MAP_LINE_LENGTH 200

// list_operations.c
char	*get_and_truncate_next_line(int fd, bool is_head);
t_list	*read_lines_into_linked_list(int fd);
char	**list_to_string_array(t_list *list, t_data *data);

// parser.c
void	parse_and_set_map_from_fd(t_data *data, int fd);

// size.c
void validate_and_set_map_properties(t_data *data, t_list *list);

// string_operations.c
void	truncate_at_newline(char *line);
char	*get_string_after_space(char *line);

// validation.c
size_t	validate_map_length(t_list *list);
void	validate_and_exit_if_not_empty(int fd);

#endif
