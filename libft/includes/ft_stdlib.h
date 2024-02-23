/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stdlib.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 18:34:54 by tsishika          #+#    #+#             */
/*   Updated: 2023/11/23 21:26:21 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STDLIB_H
# define FT_STDLIB_H

# include <stdlib.h>
# include <limits.h>

# include "ft_ctype.h"
# include "ft_strings.h"

// ft_atoi.c
int		ft_atoi(const char *str);

// ft_calloc.c
void	*ft_calloc(size_t count, size_t size);

// ft_itoa.c
char	*ft_itoa(int n);

// ft_strtol.c
long	ft_strtol(const char *str);

#endif
