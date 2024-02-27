/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 17:14:17 by tsishika          #+#    #+#             */
/*   Updated: 2024/02/28 01:09:01 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_texture_path	t_texture_path;
typedef struct s_room_color		t_room_color;
typedef struct s_map			t_map;
typedef struct s_cub			t_cub;
typedef struct s_data			t_data;

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
	int		width;
	int		height;
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
	t_cub	*cub;
};

#endif
