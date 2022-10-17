
#include "ray.h"

t_cylindre *init_cylindre(double      	x,
			  double      	y,
			  double      	z,
			  double      	radius,
			  unsigned int	color,
			  char		axe)
{
  t_cylindre *cylindre;

  if ((cylindre = malloc(sizeof(t_cylindre))) == NULL)
    return (NULL);
  cylindre->pos.x = x;
  cylindre->pos.y = y;
  cylindre->pos.z = z;
  cylindre->radius = radius;
  cylindre->color = color;
  cylindre->axe = axe;
  return (cylindre);
}

