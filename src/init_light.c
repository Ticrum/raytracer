
#include "ray.h"

t_light *init_light(double		x,
		    double		y,
		    double		z,
		    unsigned int	color)
{
  t_light *light;

  if ((light = malloc(sizeof(t_light))) == NULL)
    return (NULL);
  light->pos.x = x;
  light->pos.y = y;
  light->pos.z = z;
  light->color = color;
  return (light);
}

