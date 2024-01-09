#include <math.h>

typedef struct s_vector
{
    double x;
    double y;
} t_vector;

void init_vector(t_vector vect_pos, t_vector vect_dir, t_vector vect_plane)
{
    vect_pos.x = 0;
    vect_pos.y = 0;
    vect_dir.x = 1;
    vect_dir.y = 1;
    vect_plane.x = 0;
    vect_plane.y = 0;
}

t_vector   change_angle(t_vector vect_dir,double angle)
{
    vect_dir.x = vect_dir.x * cos(angle) - vect_dir.y * sin(angle);
    vect_dir.y = vect_dir.x * sin(angle) + vect_dir.y * cos(angle);
    return (vect_dir);
}

t_vector   change_position(t_vector vect_pos, t_vector vect_dir, double x,double y)
{
    vect_pos.x = vect_dir.x + x;
    vect_pos.y = vect_dir.y + y;
    return (vect_pos);
}

t_vector   get_vect_ray(t_vector vect_pos, t_vector vect_dir,t_vector vect_plane)
{
    t_vector vect_ray;

    vect_ray.x = vect_pos.x + vect_dir.x * vect_plane.x;
    vect_ray.y = vect_pos.y + vect_dir.y * vect_plane.y;
    return (vect_ray);
}
