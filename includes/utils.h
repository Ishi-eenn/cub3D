/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 17:20:28 by tsishika          #+#    #+#             */
/*   Updated: 2024/03/20 01:51:26 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "libft.h"
# include "struct.h"

# include <stdbool.h>
# include <fcntl.h>
# include <errno.h>
# include <stdio.h>

// cub_free.c
void	cub_free(t_cub *cub);

// find_occurrence.c
char	*find_occurrence(const char *s, int c);

// is_overflow.c
bool	is_atoi_overflow(char *line);
bool	is_rgb_overflow(char *rgb);

// open.c
void	check_and_exit_if_directory(char *file);
int		open_file_and_return_descriptor(char *file);

// print_error.c
void	print_error(char *str);
void	print_perror(char *str);
void	print_error_and_exit(char *str);
void	print_perror_and_exit(char *str);

// rgb.c
int		combine_rgb_components(char *red, char *green, char *blue);

#endif
