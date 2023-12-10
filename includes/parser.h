/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 20:13:27 by tsishika          #+#    #+#             */
/*   Updated: 2023/12/10 22:38:23 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "stdbool.h"
# include "stdio.h"

# include "utils.h"

void	validate_input_file(int argc, char **argv);

int open_file_descriptor_for_non_directory(char *file);

#endif
