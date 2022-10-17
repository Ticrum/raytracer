
#include "ray.h"

t_sphere *init_sphere(double		x,
		      double		y,
		      double		z,
		      double		radius,
		      unsigned int	color)
{
  t_sphere *sphere;

  if ((sphere = malloc(sizeof(t_sphere))) == NULL)
    return (NULL);
  sphere->pos.x = x;
  sphere->pos.y = y;
  sphere->pos.z = z;
  sphere->radius = radius;
  sphere->color = color;
  return (sphere);
}

