
#include "ray.h"

double send_light(t_zpos	pos,
		  t_object	*obj,
		  t_vect	*vect)
{
  //t_vect vect;
  t_hit_point hit;
  t_cam cam;
  //double dist;

  vect->x = obj->light[0]->pos.x - pos.x;
  vect->y = obj->light[0]->pos.y - pos.y;
  vect->z = obj->light[0]->pos.z - pos.z;
  cam.x = pos.x;
  cam.y = pos.y;// + 0.1;
  cam.z = pos.z;
  //printf("%f %f %f\n", pos.x, pos.y, pos.z);
  cam.dist = 1;
  //dist = sqrt((vect->x * vect->x) + (vect->y * vect->y) + (vect->z * vect->z));
  hit.dist = -999;
  hit.color.full = BLACK;
  draw_plan_alt(vect, &cam, obj, &hit);
  //cam.y = cam.y - 0.1;
  draw_sphere(vect, &cam, obj, &hit);
  draw_cylindre(vect, &cam, obj, &hit);
  if (hit.dist >= 0 && hit.dist <= 1)//&& hit.color.full != WHITE)//hit.color.full != WHITE)
    {
      //write(1,"a",1);
      return (-1);
    }
  return (1);
}
