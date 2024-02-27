/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 17:17:33 by tsishika          #+#    #+#             */
/*   Updated: 2024/02/27 17:28:08 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	print_error(char *str)
{
	ft_putstr_fd("ERROR:", 2);
	ft_putstr_fd(str, 2);
}

void	print_perror(char *str)
{
	ft_putstr_fd("ERROR:", 2);
	perror(str);
}

void	print_error_and_exit(char *str)
{
	print_error(str);
	exit(1);
}

void	print_perror_and_exit(char *str)
{
	print_perror(str);
	exit(1);
}
