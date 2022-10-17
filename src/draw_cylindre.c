
#include "ray.h"

static void axe_x(t_vect     	*vect,
		  t_cam       	*cam,
		  t_object    	*obj,
		  int		compt2,
		  double	*a,
		  double	*b,
		  double	*c)
{
  *a = vect->z * vect->z + vect->y * vect->y ;
  *b = 2.0 * (cam->z * vect->z + cam->y * vect->y );
  *c = cam->z * cam->z + cam->y * cam->y - (obj->cylindre[compt2]->radius * obj->cylindre[compt2]->radius);
}

static void axe_y(t_vect     	*vect,
		  t_cam       	*cam,
		  t_object    	*obj,
		  int		compt2,
		  double	*a,
		  double	*b,
		  double	*c)
{
  *a = vect->x * vect->x + vect->z * vect->z ;
  *b = 2.0 * (cam->x * vect->x + cam->z * vect->z );
  *c = cam->x * cam->x + cam->z * cam->z - (obj->cylindre[compt2]->radius * obj->cylindre[compt2]->radius);
}

static void axe_z(t_vect     	*vect,
		  t_cam       	*cam,
		  t_object    	*obj,
		  int		compt2,
		  double	*a,
		  double	*b,
		  double	*c)
{
  *a = vect->x * vect->x + vect->y * vect->y ;
  *b = 2.0 * (cam->x * vect->x + cam->y * vect->y );
  *c = cam->x * cam->x + cam->y * cam->y - (obj->cylindre[compt2]->radius * obj->cylindre[compt2]->radius);
}

void draw_cylindre(t_vect      	       	*vect,
		   t_cam       		*cam,
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
  while (compt2 < obj->nbr_cylindre)
    {
      if (obj->cylindre[compt2]->axe == 'x')
	axe_x(vect, cam, obj, compt2, &a, &b, &c);
      if (obj->cylindre[compt2]->axe == 'y')
	axe_y(vect, cam, obj, compt2, &a, &b, &c);
      if (obj->cylindre[compt2]->axe == 'z')
	axe_z(vect, cam, obj, compt2, &a, &b, &c);
      /*
      a = vect->x * vect->x + vect->y * vect->y ;
      b = 2.0 * (cam->x * vect->x + cam->y * vect->y );
      c = cam->x * cam->x + cam->y * cam->y - (obj->cylindre[compt2]->radius * obj->cylindre[compt2]->radius);
      */
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
      if (delta >= 0 && (dist[0] > 0.01 || dist[1] > 0))
	{
	  if (hit->dist < 0)
	    {
	      hit->dist = dist[0];
	      hit->color.full = obj->cylindre[compt2]->color;
	      //write(1,"c",1);
	      hit->type = 'c';
	      hit->nbr = compt2;
	    }
	  else if (dist[0] < hit->dist)
	    {
	      hit->dist = dist[0];
	      hit->color.full = obj->cylindre[compt2]->color;
	      //write(1,"c",1);
	      hit->type = 'c';
	      hit->nbr = compt2;
	    }
	}
      compt2 = compt2 + 1;
    }
}

