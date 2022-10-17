
#include "ray.h"

static double plan_print(double			vect_pos,
			 double			cam_pos,
			 double			obj_pos)
{
  double dist;
  //  t_bunny_position posi;

  dist = (obj_pos - cam_pos) / vect_pos;
  return (dist);
}

t_hit_point *draw_plan(t_vect			*vect,
		       t_cam			*cam,
		       t_object			*obj,
		       t_hit_point             	*hit)
{
  int compt2;
  double dist;

  compt2 = 0;
  while (compt2 < obj->nbr_plan)
    {
      if (obj->plan[compt2]->axe == 'x')
	dist = plan_print(vect->x, cam->x, obj->plan[compt2]->pos);
      if (obj->plan[compt2]->axe == 'y')
	dist = plan_print(vect->y, cam->y, obj->plan[compt2]->pos);
      if (obj->plan[compt2]->axe == 'z')
	dist = plan_print(vect->z, cam->z, obj->plan[compt2]->pos);
      if (dist >= 0)
	{
	  if (hit->dist < 0)
	    {
	      hit->dist = dist;
	      hit->color.full = obj->plan[compt2]->color;
	      //write(1,"p",1);
	      hit->type = 'p';
	      hit->nbr = compt2;
	      //write(1," p2",3);
	    }
	  else if(dist < hit->dist)
	    {
	      hit->dist = dist;
	      hit->color.full = obj->plan[compt2]->color;
	      //write(1,"p",1);
	      hit->type = 'p';
	      hit->nbr = compt2;
	    }
	}
      compt2 = compt2 + 1;
    }
  return (hit);
}

