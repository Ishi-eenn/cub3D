/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 20:26:38 by tsishika          #+#    #+#             */
/*   Updated: 2023/12/14 11:27:03 by tsishika         ###   ########.fr       */
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
