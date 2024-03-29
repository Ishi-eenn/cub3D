/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 17:14:17 by tsishika          #+#    #+#             */
/*   Updated: 2024/03/20 04:06:27 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include <stddef.h>
# include <stdbool.h>

typedef enum e_size				t_size;

typedef struct s_vector			t_vector;
typedef struct s_ray			t_ray;
typedef struct s_texture_path	t_texture_path;
typedef struct s_room_color		t_room_color;
typedef struct s_map			t_map;
typedef struct s_cub			t_cub;
typedef struct s_img			t_img;
typedef struct s_texture		t_texture;
typedef struct s_wall			t_wall;
typedef struct s_mouse			t_mouse;
typedef struct s_mlx			t_mlx;
typedef struct s_data			t_data;

enum e_size {
	WINDOW_WIDTH	= 800,
	WINDOW_HEIGHT	= 600
};

struct s_vector
{
	double	position_x;
	double	position_y;
	double	direction_x;
	double	direction_y;
	double	plane_x;
	double	plane_y;
};

struct s_ray
{
	double	camera_x;
	double	ray_dir_x;
	double	ray_dir_y;
	int		map_x;
	int		map_y;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	int		step_x;
	int		step_y;
	int		hit;
	int		side;
	double	perp_wall_dist;
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
	size_t	larger_length;
	int		scale;
	char	**map_data;
};

struct s_cub
{
	t_texture_path	*texture_path;
	t_room_color	*room_color;
	t_map			*map;
};

struct s_img
{
	void	*img_ptr;
	char	*addr;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
};

struct s_texture
{
	void	*img_ptr;
	char	*addr;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
	int		width;
	int		height;
};

struct s_wall
{
	int		line_height;
	int		draw_start;
	int		draw_end;
	int		side;
	int		texture_x;
	double	texture_position;
	double	step;
};

struct s_mouse
{
	int	button;
	int	x;
};

struct s_mlx
{
	void		*mlx;
	void		*win;
	t_img		img;
	t_texture	texture[4];
	t_mouse		mouse;
	bool		map;
};

struct s_data
{
	t_cub		*cub;
	t_vector	*vector;
	t_mlx		*mlx;
};

#endif
