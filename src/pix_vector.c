
#include "ray.h"

t_vect *pix_vector(t_bunny_pixelarray	*pix,
		   int			x,
		   int			y,
		   t_cam		*cam,
		   t_vect		*vect)
{
  vect->x = pix->clipable.buffer.width / 2 - x;
  vect->y = pix->clipable.buffer.height / 2 - y;
  vect->z = cam->dist;
  return (vect);
}

