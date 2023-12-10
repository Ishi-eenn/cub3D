/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 20:24:57 by tsishika          #+#    #+#             */
/*   Updated: 2023/12/11 02:39:06 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <fcntl.h>
# include <stdbool.h>
# include <errno.h>
# include <stdio.h>

# include "libft.h"

# define ERROR_ARGC "The number of arguments is incorrect.\n"
# define ERROR_ARGV "Incorrect file name entered.\n"

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

#endif
