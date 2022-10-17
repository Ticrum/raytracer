
#include "ray.h"

void draw_sphere(t_vect		       	*vect,
		 t_cam			*cam,
		 t_object		*obj,
		 t_hit_point		*hit)
{
  double a;
  double b;
  double c;
  double delta;
  int compt2;
  //t_bunny_position posi;
  double dist[2];

  compt2 = 0;
  while (compt2 < obj->nbr_sphere)
    {
      a = vect->x * vect->x + vect->y * vect->y + vect->z * vect->z;
      b = 2.0 * (cam->x * vect->x + cam->y * vect->y + cam->z * vect->z);
      c = cam->x * cam->x + cam->y * cam->y + cam->z * cam->z - (obj->sphere[compt2]->radius * obj->sphere[compt2]->radius);
      delta = b * b - 4 * a * c;
      if (delta == 0)
	dist[0] = -b / (2 * a);
      if (delta > 0)
	{
	  dist[0] = (-b + sqrt(delta)) / (2 * a);
	  dist[1] = (-b - sqrt(delta)) / (2 * a);
	  if (dist[1] < dist[0] && dist[1] > 0)
	    dist[0] = dist[1];
	}
      //printf("%f, %f\n", dist[0], dist[1]);
      if (delta >= 0 && (dist[0] > 0.01 || dist[1] > 0))
	{
	  if (hit->dist < 0)
	    {
	      //write(1,"a",1);
	      hit->dist = dist[0];
	      hit->color.full = obj->sphere[compt2]->color;
	      hit->type = 's';
	      hit->nbr = compt2;
	    }
	  else if (dist[0] < hit->dist)
	    {
	      hit->dist = dist[0];
	      hit->color.full = obj->sphere[compt2]->color;
	      hit->type = 's';
	      hit->nbr = compt2;
	    }
	}
      compt2 = compt2 + 1;
    }
}

