/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 15:47:33 by tsishika          #+#    #+#             */
/*   Updated: 2024/03/20 01:38:24 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H

# include <math.h>

# include "struct.h"

void	init_ray(t_data *data, t_ray *ray, int x);

void	calculate_step_and_side_dist(t_data *data, t_ray *ray);
void	calculate_wall_height(t_data *data, t_ray *ray, t_wall *wall);

#endif
