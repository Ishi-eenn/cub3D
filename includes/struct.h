/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 17:14:17 by tsishika          #+#    #+#             */
/*   Updated: 2024/03/10 22:10:46 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include <stddef.h>

typedef struct s_vector			t_vector;
typedef struct s_texture_path	t_texture_path;
typedef struct s_room_color		t_room_color;
typedef struct s_map			t_map;
typedef struct s_cub			t_cub;
typedef struct s_data			t_data;

struct s_vector
{
	double	position_x;
	double	position_y;
	double	direction_x;
	double	direction_y;
	double	plane_x;
	double	plane_y;
};

struct s_texture_path
{
	char	*north;
	char	*south;
	char	*west;
	char	*east;
};

struct s_room_color
{
	int	floor;
	int	ceiling;
};

struct s_map
{
	size_t	width;
	size_t	height;
	char	**map_data;
};

struct s_cub
{
	t_texture_path	*texture_path;
	t_room_color	*room_color;
	t_map			*map;
};

struct s_data
{
	t_cub		*cub;
	t_vector	*vector;
};

#endif
