
#include "ray.h"

static t_vect vectn_s(t_object *obj,
		      int	compt,
		      t_zpos	pos)
{
  t_vect vectn;

  vectn.x = pos.x - obj->sphere[compt]->pos.x;
  vectn.y = pos.y - obj->sphere[compt]->pos.y;
  vectn.z = pos.z - obj->sphere[compt]->pos.z;
  return (vectn);
}

static t_vect vectn_c(t_object *obj,
		      int	compt,
		      t_zpos	pos)
{
  t_vect vectn;

  vectn.x = pos.x - obj->cylindre[compt]->pos.x;
  vectn.y = pos.y - obj->cylindre[compt]->pos.y;
  vectn.z = pos.z - obj->cylindre[compt]->pos.z;
  if (obj->cylindre[compt]->axe == 'x')
    vectn.x = 0;
  if (obj->cylindre[compt]->axe == 'y')
    vectn.y = 0;
  if (obj->cylindre[compt]->axe == 'z')
    vectn.z = 0;
  return (vectn);
}

static t_vect vectn_p(t_object *obj,
		      int	compt)
{
  t_vect vectn;

  vectn.x = 0;
  vectn.y = 0;
  vectn.z = 0;
  
  if (obj->plan[compt]->axe == 'x')
    vectn.x = 1;
  if (obj->plan[compt]->axe == 'y')
    vectn.y = 1;
  if (obj->plan[compt]->axe == 'z')
    vectn.z = 1;
  
  return (vectn);
}

double get_angle(t_vect *light,
		 t_object *obj,
		 char type,
		 int compt,
		 t_zpos pos)
{
  t_vect vectn;
  double ab;
  double len[2];

  if (type == 's')
    vectn = vectn_s(obj, compt, pos);
  if (type == 'c')
    vectn = vectn_c(obj, compt, pos);
  if (type == 'p')
    vectn = vectn_p(obj, compt);
  len[0] = sqrt((vectn.x * vectn.x) + (vectn.y * vectn.y) + (vectn.z * vectn.z));
  len[1] = sqrt((light->x * light->x) + (light->y * light->y) + (light->z * light->z));
  ab = (vectn.x * light->x) + (vectn.y * light->y) + (vectn.z * light->z);
  return (ab / (len[0] * len[1]));
}

