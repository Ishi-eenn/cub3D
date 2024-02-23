/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stdio.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 18:12:27 by tsishika          #+#    #+#             */
/*   Updated: 2023/11/28 09:17:01 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STDIO_H
# define FT_STDIO_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4096
# endif

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

# include "ft_string.h"

// get_next_line.c
char	*get_next_line(int fd);

// ft_putchar_fd.c
void	ft_putchar_fd(char c, int fd);

// ft_putendl_fd.c
void	ft_putendl_fd(char *s, int fd);

// ft_putnbr_fd.c
void	ft_putnbr_fd(int n, int fd);

// ft_putstr_fd.c
void	ft_putstr_fd(char *s, int fd);

#endif
