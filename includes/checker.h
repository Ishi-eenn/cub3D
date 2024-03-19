/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 21:33:07 by tsishika          #+#    #+#             */
/*   Updated: 2024/03/15 22:50:20 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "stdbool.h"

# include "struct.h"
# include "utils.h"
# include "parser.h"

// check_closed.c
void	validate_map_walkability(t_data *data);

// check_map.c
void	check_input_data(t_data *data);

// check_player.c
void	scan_map_and_check_player(t_data *data);

#endif
