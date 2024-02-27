/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 17:29:22 by tsishika          #+#    #+#             */
/*   Updated: 2024/02/27 17:55:40 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

#include "libft.h"
#include <stdbool.h>

# define ERROR_ARGC "The number of arguments is incorrect.\n"
# define ERROR_ARGV "Incorrect file name entered.\n"


// file_name.c
void	validate_input_file(int argc, char **argv);

// parser.c
void parser(int argc, char *argv);

#endif
