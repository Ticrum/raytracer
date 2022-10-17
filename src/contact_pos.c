
#include "ray.h"

t_zpos contact_pos(t_vect	*vect,
		   double	dist,
		   t_cam	*cam)
{
  t_zpos pos;
  //double vect_len;
  double ratio;
  
  //vect_len = sqrt((vect->x * vect->x) + (vect->y * vect->y) + (vect->z * vect->z));
  ratio = dist;// / vect_len;
  pos.x = cam->x + vect->x * ratio;
  pos.y = cam->y + vect->y * ratio;
  pos.z = cam->z + vect->z * ratio;
  //printf("%f %f %f %f %f %f\n", pos.x, pos.y, pos.z, vect_len, dist, ratio);
  return (pos);
}

