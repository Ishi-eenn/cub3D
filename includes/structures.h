/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 22:47:39 by tsishika          #+#    #+#             */
/*   Updated: 2023/12/14 10:20:00 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

typedef struct s_texture_path	t_texture_path;
typedef struct s_room_color		t_room_color;
typedef struct s_map			t_map;
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

struct s_data
{
	t_map			*map;
	t_texture_path	*texture_path;
	t_room_color	*room_color;
};

#endif
