
#include "ray.h"

t_plan *init_plan(double	pos,
		  char		axe,
		  unsigned int	color)
{
  t_plan *plan;

  if ((plan = malloc(sizeof(t_plan))) == NULL)
    return (NULL);
  plan->pos = pos;
  plan->axe = axe;
  plan->color = color;
  return (plan);
}

